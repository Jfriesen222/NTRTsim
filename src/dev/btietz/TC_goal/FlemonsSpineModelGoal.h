/*
 * Copyright © 2012, United States Government, as represented by the
 * Administrator of the National Aeronautics and Space Administration.
 * All rights reserved.
 * 
 * The NASA Tensegrity Robotics Toolkit (NTRT) v1 platform is licensed
 * under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0.
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific language
 * governing permissions and limitations under the License.
*/

#ifndef FLEMONS_SPINE_MODEL_GOAL_H
#define FLEMONS_SPINE_MODEL_GOAL_H

/**
 * @file FlemonsSpineModelGoal.h
 * @brief Implementing the tetrahedral complex spine inspired by Tom Flemons
 * @author Brian Mirletz
 * @date January 2015
 * @version 1.1.0
 * $Id$
 */

#include "examples/learningSpines/BaseSpineModelLearning.h"
#include "dev/btietz/TC_goal/BaseSpineModelGoal.h"

#include "LinearMath/btVector3.h"

class tgWorld;
class tgStructureInfo;
class tgBox;
class tgSpringCableActuator;

/**
 * This class implements the tetrahedral complex tensegrity spine
 * based on the work of <a href="http://www.intensiondesigns.com/models.html">Tom Flemons</a>
 * This is similar to the version in examples, but uses muscles with contact dynamics
 */
class FlemonsSpineModelGoal : public BaseSpineModelGoal
{
public: 

    FlemonsSpineModelGoal(int segments, double goalAngle);

    virtual ~FlemonsSpineModelGoal();
    
    virtual void setup(tgWorld& world);
    
    virtual void teardown();
        
    virtual void step(double dt);
    

};

#endif // FLEMONS_SPINE_MODEL_H
