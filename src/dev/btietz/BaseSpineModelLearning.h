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

#ifndef BASE_SPINE_MODEL_LEARNING_H
#define BASE_SPINE_MODEL_LEARNING_H

#include "core/tgModel.h" 
#include "core/tgSubject.h"
#include "LinearMath/btVector3.h"
#include "boost/multi_array.hpp"
#include <map>
#include <set>
#include <string>
#include <vector>

class tgWorld;
class tgStructureInfo;
class tgLinearString;

class BaseSpineModelLearning: public tgSubject<BaseSpineModelLearning>,
                                 public tgModel
{
public: 
	
	typedef std::map<std::string, std::vector<tgLinearString*> > MuscleMap;
	
    virtual ~BaseSpineModelLearning();
    
    virtual void setup(tgWorld& world);
    
    virtual void teardown();
        
    virtual void step(double dt);
    
    virtual std::vector<double> getSegmentCOM(const int n) const;
      
    virtual const std::vector<tgLinearString*>& getMuscles(const std::string& key) const;
    
    virtual const std::vector<tgLinearString*>& getAllMuscles();
    
    virtual const int getSegments();
    
    virtual std::size_t getNumberofMuslces() const
    {
        return m_allMuscles.size();
    }
    
protected:
	
	BaseSpineModelLearning(int segments);
	
    std::vector<tgLinearString*> m_allMuscles;
	
    std::vector<tgModel*> m_allSegments;

    MuscleMap m_muscleMap;
    
    const std::size_t m_segments;
};

#endif // BASE_SPINE_MODEL_H