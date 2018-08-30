#ifndef SPRITE_H
#define SPRITE_H

#include "jgl.h"

typedef jml::Vector<long double, 2> pVar;
typedef jml::Vector<unsigned int, 2> dVar;


class Sprite
{
    public:
        Sprite(pVar p, dVar d, jgl::Color c, jgl::Object* s, jutil::String str);
        virtual ~Sprite();
        /*
        * SETTERS
        */
        void setPos(jml::Vector<long double, 2>); // sets the Pos
        void setDims(jml::Vector<unsigned int, 2>);
        void setImageName(jutil::String);
        void setColor(jgl::Color);
        void setShape(jgl::Object*);

        /**
        * GETTERS
        */
        jml::Vector<long double, 2> getPos() const;
        jml::Vector<unsigned int, 2> getDims() const;
        jutil::String getImageName() const;
        jgl::Color getColor() const;
        jgl::Object* getShape() const;

        /**
        * CLASS FUNTIONS
        */



    protected:
        jml::Vector<long double, 2> pos; // sprite pos x,y
        jml::Vector<unsigned int, 2> dims;
        jutil::String imageName; // name/filepath of the image to load
        jgl::Color color;
        jgl::Object* shape;

    private:




};

#endif // SPRITE_H
