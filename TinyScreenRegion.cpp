#include <TinyScreen.h>
#include "TinyScreenRegion.h"

TinyScreenRegion::TinyScreenRegion(void)
{
	_IsInitialized=false;
	_ts=NULL;
}

void TinyScreenRegion::begin(TinyScreen *ts, uint8_t left, uint8_t top, uint8_t width, uint8_t height)
{
	_ts=ts;
	_top=top;
	_left=left;
	_height=height;
	_width=width;
	_right=left+width;
	_bottom=top+height;
	_IsInitialized=true;
}

void TinyScreenRegion::DrawRect(uint8_t left, uint8_t top, uint8_t width, uint8_t height, uint8_t fill, uint8_t r, uint8_t g, uint8_t b)
{
	_ts->drawRect(left+_left,top+_top,min(width,_width-left),min(height,_height-top),fill,r,g,b);
}

void TinyScreenRegion::DrawRect(uint8_t left, uint8_t top, uint8_t width, uint8_t height, uint8_t fill, uint8_t color)
{
	_ts->drawRect(left+_left,top+_top,min(width,_width-left),min(height,_height-top),fill,color);
}

void TinyScreenRegion::Clear(void)
{
	_ts->clearWindow(_left,_top,_width,_height);
}

void TinyScreenRegion::Fill(uint8_t r, uint8_t g, uint8_t b)
{
	DrawRect(0, 0, _width, _height, true, r, g, b);
}

void TinyScreenRegion::Fill(uint8_t color)
{
	DrawRect(0, 0, _width, _height, true, color);
}

void TinyScreenRegion::CenterText(const char *text, uint8_t textColor, uint8_t bgColor)
{
	uint8_t x, y, ht, wd, len;

	_ts->getStringMeasurements(text,&ht,&wd,&len);
	_ts->fontColor(textColor, bgColor);
	x=(_width-wd)/2;
	y=(_height-ht)/2;
	_ts->setCursor(x+_left, y+_top);
	_ts->print(text);
}

void TinyScreenRegion::SetCursor(uint8_t x, uint8_t y)
{
	_ts->setCursor(x+_left, y+_top);
}