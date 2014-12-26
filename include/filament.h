/*
 *  filament.cpp
 *  
 *
 *  Created by Simon Freedman on 12/22/2014
 *  Copyright 2014 University of Chicago. All rights reserved.
 *
 */

//=====================================
//include guard
#ifndef __FILAMENT_H_INCLUDED__
#define __FILAMENT_H_INCLUDED__

//=====================================
// forward declared dependencies

//=====================================
//included dependences
#include "string"
#include "vector"
#include "actin.h"
#include "Link.h"

//=====================================
//actin filament class
class filament
{
    public:

        filament(double x0, double y0, double phi0, int nrod, double fovx, double fovy, int nx, int ny, 
                double vis, double deltat, bool isStraight,
                double rodLength, double linkLength, double stretching, double bending); 
        
        ~filament();
    
        void set_shear(double g);

        void update(double t);
        
        void update_bending();
        
        void update_stretching();

        void update_shear(); 
        
        actin * get_rod(int i);

        std::vector<std::vector<std::vector<int> > > get_quadrants();
        
        std::string write();
        
        std::string to_string();
        
        bool operator==(const filament& that);    
    

    private:
        
        double fov[2], gamma, dt;
        
        int nq[2];

        std::vector<std::vector<int> > quads_filled; //vector of two vectors(x and y quadrants) of integers
        
        std::vector<actin *> rods;
        
        std::vector<Link *> lks;
       
        std::vector<int> tmp;
};

#endif
