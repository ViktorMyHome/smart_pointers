#include <iostream>
#include <memory>


class Point
{
public:
int x;int y;
Point(){
    x=0;y=0;
}
Point(int xx, int yy)
{
    x=xx;y=yy;
}

void setValue(int xx, int yy)
{
    x=xx;y=yy;
}

void Display(){
    std::cout<<"x="<<x<<"y="<<y<<std::endl;
}
 
};


void DisplayUniqPtr(Point *p)
{
    if(!p){
        return;
    }
    std::cout<<"x="<<p->x<<"y="<<p->y<<std::endl;
}

void show(std::unique_ptr<Point> &p)//by reference
{
    std::cout<<p.get()->x<<std::endl;
}


int main() {

 //   Point *ptr=new Point();

    std::unique_ptr<Point> p(new Point());
    std::unique_ptr<Point> p3=std::make_unique<Point>(4,4);

    if(p3){
        std::cout<<"p3 is not empty before move"<<std::endl;
    }
    else{
        std::cout<<"p3 is emty before move"<<std::endl;
    }

 //   show(std::move(p3));//empty after, by value
    show(p3);//not empty after, by reference
 //   DisplayUniqPtr(p3.get());//not empty after
    p3.reset();

    if(p3){
        std::cout<<"p3 is not empty after move"<<std::endl;
    }
    else{
        std::cout<<"p3 is emty after move"<<std::endl;
    }

    p->setValue(3,3);
    p->Display();
 //   p3->Display();
    Point *p1;
    p1=p.get();
    DisplayUniqPtr(p.get());
    //p.reset();

    p1->Display();
    p=nullptr;
    return 0;
}

