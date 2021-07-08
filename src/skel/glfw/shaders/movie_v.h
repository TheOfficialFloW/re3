#ifndef __movie_v__
#define __movie_v__

/*
  void main(
    float2 inPos,
    float2 inTex,
    float4 out pos : POSITION,
    float2 out texcoord : TEXCOORD0
  ) {
    texcoord = inTex;
    pos = float4(inPos, 1.f, 1.f);
  }
*/

static unsigned int size_movie_v = 276;
static unsigned char movie_v[] __attribute__((aligned(16))) = {
  0x47, 0x58, 0x50, 0x00, 0x01, 0x05, 0x50, 0x03, 0x14, 0x01, 0x00, 0x00, 0x0a, 0xf8, 0x9c, 0x1c, 
  0xb3, 0x51, 0x01, 0x8f, 0x04, 0x00, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 
  0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x05, 0x00, 0x00, 0x00, 
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x74, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0xc0, 0x3d, 0x03, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x74, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6c, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5c, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x54, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x06, 
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x44, 0xfa, 0x80, 0x00, 0x08, 0x83, 0x21, 0x05, 0x80, 0x38, 
  0x01, 0x00, 0x04, 0x90, 0x85, 0x11, 0xa5, 0x08, 0x01, 0x80, 0x56, 0x90, 0x81, 0x11, 0x83, 0x08, 
  0x00, 0x00, 0x20, 0xa0, 0x00, 0x50, 0x27, 0xfb, 0x20, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 
  0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x69, 0x6e, 0x50, 0x6f, 0x73, 0x00, 0x69, 0x6e, 
  0x54, 0x65, 0x78, 0x00, 
};

#endif
