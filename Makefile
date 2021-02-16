TITLE		:=	"Grand Theft Auto III"
TITLE_ID	:=	GTA300000
TARGET		:=	GTA3

SOURCES		:=	src src/animation src/audio src/audio/oal src/audio/eax src/buildings src/control src/collision src/core src/entities src/math src/modelinfo src/objects src/peds src/render src/rw src/save src/skel src/skel/glfw src/text src/vehicles src/weapons src/extras src/fakerw
INCLUDES	:=	src src/animation src/audio src/audio/oal src/audio/eax src/buildings src/control src/collision src/core src/entities src/math src/modelinfo src/objects src/peds src/render src/rw src/save src/skel src/skel/glfw src/text src/vehicles src/weapons src/extras src/fakerw librw

CFILES		:=	$(foreach dir,$(SOURCES), $(wildcard $(dir)/*.c))
CPPFILES	:=	$(foreach dir,$(SOURCES), $(wildcard $(dir)/*.cpp))
BINFILES	:=	$(foreach dir,$(DATA), $(wildcard $(dir)/*.bin))
OBJS		:=	$(addsuffix .o,$(BINFILES)) $(CFILES:.c=.o) $(CPPFILES:.cpp=.o) 

INCLUDE		:=	$(foreach dir,$(INCLUDES),-I$(dir))

PREFIX		=	arm-vita-eabi
CC			=	$(PREFIX)-gcc
CXX			=	$(PREFIX)-g++
ARCH		:=	-mtune=cortex-a9 -march=armv7-a -mfpu=neon
CFLAGS		:=	-g -Wl,-q,--no-enum-size-warning -fno-short-enums -fno-optimize-sibling-calls -O2 -ftree-vectorize -mfloat-abi=hard -fno-builtin-memcpy $(ARCH) $(DEFINES)
CFLAGS		+=	$(INCLUDE) -DPSP2 -DNDEBUG -DMASTER -DLIBRW -DRW_GL3 -DAUDIO_OAL -DLIBRW_GLAD
CXXFLAGS	:=	$(CFLAGS) -fno-rtti -fno-exceptions
ASFLAGS		:=	-g $(ARCH)
LDFLAGS		=	-g $(ARCH) -Wl,-Map,$(notdir $*.map)
LIBS		:=	-lrw -lopenal -lSDL2 -lvita2d -lvitagl -lSceAppMgr_stub -lSceDisplay_stub -lSceCommonDialog_stub -lSceLibKernel_stub \
				-lSceSysmodule_stub -lvitashark -lSceShaccCg_stub -lvitagl -lmathneon -lSceGxm_stub -lScePower_stub \
				-lSceCtrl_stub -lSceHid_stub -lSceAudio_stub -lSceTouch_stub -lm -lpthread -lmpg123 -lSceMotion_stub

all:	$(TARGET).vpk

%.vpk:	eboot.bin
	vita-mksfoex -s TITLE_ID=$(TITLE_ID) -d ATTRIBUTE2=12 $(TITLE) param.sfo
	vita-pack-vpk -s param.sfo -b eboot.bin \
		--add sce_sys/icon0.png=sce_sys/icon0.png \
		--add sce_sys/livearea/contents/bg.png=sce_sys/livearea/contents/bg.png \
		--add sce_sys/livearea/contents/startup.png=sce_sys/livearea/contents/startup.png \
		--add sce_sys/livearea/contents/template.xml=sce_sys/livearea/contents/template.xml \
	$(TARGET).vpk

eboot.bin:	$(TARGET).velf
	vita-make-fself -c -s $< $@

%.velf:	%.elf
	vita-elf-create $< $@

$(TARGET).elf:	$(OBJS)
	$(CXX) $(CXXFLAGS) $^ $(LIBS) -o $@

clean:
	@rm -rf $(TARGET).vpk $(TARGET).velf $(TARGET).elf $(OBJS) eboot.bin param.sfo
