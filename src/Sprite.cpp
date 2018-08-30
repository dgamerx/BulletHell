#include "Sprite.h"




Sprite::Sprite(pVar p, dVar d, jgl::Color c, jgl::Object* s, jutil::String str)
    :
        pos(p),
        dims(d),
        imageName(str),
        color(c),
        shape(s)
{


}




Sprite::~Sprite()
{
    //dtor
}


void Sprite::setPos(jml::Vector<long double, 2> p){
    pos = p;

} // sets the Pos

void Sprite::setDims(jml::Vector<unsigned int, 2> d){
    dims = d;
}
void Sprite::setImageName(jutil::String str){
    imageName = str;
}
void Sprite::setColor(jgl::Color c){
    color = c;
}
void Sprite::setShape(jgl::Object* s){
    shape = s;
}

/**
* GETTERS
*/
jml::Vector<long double, 2> Sprite::getPos() const {
    return pos;
}
jml::Vector<unsigned int, 2> Sprite::getDims() const {
    return dims;
}
jutil::String Sprite::getImageName() const {
    return imageName;
}
jgl::Color Sprite::getColor() const {
    return color;
}
jgl::Object* Sprite::getShape() const {
    return shape;
}







