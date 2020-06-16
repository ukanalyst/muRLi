#ifndef ICONTEXTVIEW_H
#define ICONTEXTVIEW_H

#include "../view.hpp"
#include "../display.hpp"

namespace Murli
{
    class IconTextView : public View
    {
        public:
            IconTextView(std::string text, const unsigned char* iconFont, uint8_t iconNr) : 
                _text(text), _iconFont(iconFont), _iconNr(iconNr) { }

            void drawFrame(DisplayCtrl& display) override
            {
                display.setFontPosCenter();
                uint8_t displayCenter = (display.getDisplayHeight() - 10) / 2;

                display.setFont(_iconFont);
                display.drawGlyph(10, displayCenter, _iconNr);
                
                display.setFont(u8g2_font_5x8_tf);
                display.drawStr(35, displayCenter, _text.c_str());

                display.setFontPosBaseline();                
            }

            void setText(const std::string& text) 
            {
                _text = text;
            }

            void setFont(const unsigned char* iconFont)
            {
                _iconFont = iconFont;
            }

            void setIconNr(uint8_t iconNr)
            {
                _iconNr = iconNr;
            }
        
        private:
            std::string _text;
            const unsigned char* _iconFont;
            uint8_t _iconNr;
    };
}

#endif // ICONTEXTVIEW_H