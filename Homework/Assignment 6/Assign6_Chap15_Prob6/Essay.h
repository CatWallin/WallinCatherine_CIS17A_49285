
/* 
 * File:   Essay.h
 * Author: Catherine
 *
 * Created on November 25, 2020, 1:26 PM
 */

#ifndef ESSAY_H
#define ESSAY_H

#include "GradedActivity.h"

class Essay : public GradedActivity
{
    protected:
        int grammer;
        int spelling;
        int length;
        int content;
    public:
        //default constructor
        Essay(){
            grammer = 0;
            spelling = 0;
            length = 0;
            content = 0;
            score = 0;
        }
        //constructor
        Essay(int g, int s, int l, int c){
            grammer = g;
            spelling = s;
            length = l;
            content = c;
            score = (grammer + spelling) + (length + content);
        }
        
        //mutator functions
        void setGrammer(int g){
            grammer = g;
            score = (grammer + spelling) + (length + content);
        }
        void setSpelling(int s){
            spelling = s;
            score = (grammer + spelling) + (length + content);
        }
        void setLength(int l){
            length = l;
            score = (grammer + spelling) + (length + content);
        }
        void setContent(int c){
            content = c;
            score = (grammer + spelling) + (length + content);
        }
             
        //accessor functions
        int getGrammer(){
            return grammer;
        }
        int getSpelling(){
            return spelling;
        }
        int getLength(){
            return length;
        }
        int getContent(){
            return content;
        }
       
};

#endif /* ESSAY_H */

