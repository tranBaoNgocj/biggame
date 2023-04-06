#ifndef ELEMENT_H
#define ELEMENT_H

struct ball
{
    int height;
    int position;
    int currentBarrierPosition;
    ball(int _height, int _position, int _currentBarrierPosition);
};
#endif