/*
 * IPState.cpp
 *
 *  Created on: May 3, 2012
 *      Author: frferrara
 */

#include "IPState.hpp"

void IPState::changeState( ImageProcessing * ip,
                           IPState * state ) {
    ip->changeState( state );
}
