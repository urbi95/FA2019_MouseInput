#ifndef MOUSE_INPUT_SQUARE_H
#define MOUSE_INPUT_SQUARE_H

class Square{
private:
    int m_x;
    int m_y;
    int m_width;

public:
    explicit Square(int x=0, int y=0, int width=20){
        m_x = x;
        m_y = y;
        m_width = width;
    }
    //Setters & Getters
    void setX(int x){
        m_x = x;
    }
    void setY(int y){
        m_y = y;
    }
    int getX(){
        return m_x;
    }
    int getY(){
        return m_y;
    }

    bool isInside(int x, int y){
        return (m_x < x) && (x < m_x + m_width) && (m_y < y) && (y < m_y + m_width);
    }
    bool render(SDL_Renderer* ren){
        SDL_Rect fillRect = {m_x, m_y, m_width, m_width};
        SDL_SetRenderDrawColor(ren, 0xFF, 0x00, 0x00, 0xFF);
        SDL_RenderFillRect(ren, &fillRect);
    }

};

#endif