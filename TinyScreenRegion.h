#ifndef TinyScreenRegion_H
#define TinyScreenRegion_H

#include <Arduino.h>

#define TS_FULLWIDTH 96
#define TS_FULLHEIGHT 64

class TinyScreenRegion
{
public:
  TinyScreenRegion(void);
  void begin(TinyScreen *ts, uint8_t left, uint8_t top, uint8_t width, uint8_t height);
  void Clear(void);
  void Fill(uint8_t r, uint8_t g, uint8_t b);
  void Fill(uint8_t color);
  void DrawRect(uint8_t left, uint8_t top, uint8_t width, uint8_t height, uint8_t fill, uint8_t r, uint8_t g, uint8_t b);
  void DrawRect(uint8_t left, uint8_t top, uint8_t width, uint8_t height, uint8_t fill, uint8_t color);
  void CenterText(const char *text, uint8_t textColor, uint8_t bgColor);
  void SetCursor(uint8_t x, uint8_t y);

private:
  TinyScreen *_ts;
  bool _IsInitialized;
  uint8_t _left, _top, _right, _bottom, _width, _height;
};

#endif