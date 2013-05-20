//
//  GAnimate.h
//  animateTest
//
//  Created by Ghost on 13-5-20.
//
//

#ifndef __animateTest__GAnimate__
#define __animateTest__GAnimate__

#include "cocos2d.h"

USING_NS_CC;

class GAnimate : public CCAnimate
{
public:
    static GAnimate* create(CCAnimation *pAnimation, int nAnimationIndex = 0);
    virtual bool init(CCAnimation *pAnimation, int nAnimationIndex);
    virtual void startWithTarget(CCNode *pTarget);
    
    CC_SYNTHESIZE(int, m_nAnimationIndex, AnimationIndex);
    
    bool m_bFirstStart;
};

#endif /* defined(__animateTest__GAnimate__) */
