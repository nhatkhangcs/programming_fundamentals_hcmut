/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 15.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

class Point {
private:
    int x;
    int y;
public:
    Point(int x=0, int y=0){
        this->x = x;
        this->y = y;
    }

    string toString() const
    {
        string res = "<Point[" + to_string(x) + "," + to_string(y) + "]>";
        return res;
    }

    int distanceTo(const Point & otherPoint) const{
        int dis = ceil(sqrt((otherPoint.x - x)*(otherPoint.x - x)+(otherPoint.y - y)*(otherPoint.y - y)));
        return dis;
    }

    int xcor() const{
        return x;
    }

    int ycor() const
    {
        return y;
    }
};

class Node {
private:
    Point point;
    Node * next;

    friend class Path;

public:
    Node(const Point & point=Point(), Node * next=NULL){
        this->point = point;
        this->next = next;
    }
    string toString() const{
        string res = "<Node[" + point.toString() + "]>";
        return res;
    }
};

class Path {
private:
    Node * head;
    Node * tail;
    int count;
    int length;

public:
    Path()
    {
        head = tail = NULL;
        this->count = 0;
        this->length = -1;
    }

    ~Path()
    {
        if (head == NULL) return;
        Node* des = head->next;
        Node* cur = NULL;
        while (des != NULL) {
            cur = des->next;
            delete des;
            des = cur;
        }
        head = NULL;
    }

    void addPoint(int x, int y){
        Node* temp = head;
        if(head == NULL)
        {
            tail = head;
            length = 0;
            head = new Node(Point(x,y));
        }
        else{
            while(temp->next!= NULL)
            {
                temp=temp->next;
            }
            temp->next = new Node(Point(x,y));
            tail = temp->next;
            length += tail->point.distanceTo(temp->point);
        }     
        count++;
    }

    string toString() const
    {
        Node* temp = head;
        string res = "<Path[count:" + to_string(count) + ",length:" + to_string(length) + ",[";
        while(temp != NULL)
            {
                res += temp->toString();
                temp=temp->next;
                if (temp != NULL) res+=",";
            }
        res += "]]>";
        return res;
    }

    Point getLastPoint() const{
        Node* temp = head;
        if (temp == NULL)
        {
            temp = new Node();
            return head->point;
        }

        else{
            while(temp->next!= NULL)
            {
                temp=temp->next;
            }
            return temp->point;
        }
    }

    int getLength()
    {
        return length;
    }
};

class Character {
private:
    string name;
    Path * path;

public:
    Character(const string & name="")
    {
        this->name = name;
        path = new Path();
    }

    ~Character()
    {
        delete path;
    }

    string getName() const{
        return this->name;
    }

    void setName(const string & name){
        this->name=name;
    }

    void moveToPoint(int x, int y){
        path->addPoint(x,y);
    }

    string toString() const{
        string res = "<Character[name:" + getName() + ",path:" + path->toString() + "]>";
        return res;
    }

    int getLength() const
    {
        return path->getLength();
    }

    Point getCurrentPosition() const
    {
        return path->getLastPoint();
    }
};

bool rescueSherlock(
        const Character & chMurderer,
        const Character & chWatson,
        int maxLength,
        int maxDistance,
        int & outDistance
        ) {
            if(chWatson.getLength() - chMurderer.getLength() <= maxLength) 
            {
                outDistance = chMurderer.getCurrentPosition().distanceTo(chWatson.getCurrentPosition());
                if (outDistance <= maxDistance) return true;
                else return false;
            }

            else {
                outDistance = -1;
                return false;
            }
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */