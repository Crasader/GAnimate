//
//  GAnimate.cpp
//  animateTest
//
//  Created by Ghost on 13-5-20.
//
//

#include "GAnimate.h"

GAnimate* GAnimate::create(CCAnimation *pAnimation, int nAnimationIndex)
{
    GAnimate *animate = new GAnimate();
    animate->init(pAnimation, nAnimationIndex);
    animate->autorelease();
    return animate;
}

bool GAnimate::init(CCAnimation *pAnimation, int nAnimationIndex)
{
    if (initWithAnimation(pAnimation))
    {
        this->setAnimationIndex(nAnimationIndex);
        m_nNextFrame = nAnimationIndex;
        m_elapsed = nAnimationIndex * m_fDuration / m_pSplitTimes->size();
    }
    return true;
}

void GAnimate::startWithTarget(CCNode *pTarget)
{
    if (m_bFirstTick) CCFiniteTimeAction::startWithTarget(pTarget);
        else CCActionInterval::startWithTarget(pTarget);
    CCSprite *pSprite = (CCSprite*)(pTarget);
    
    CC_SAFE_RELEASE(m_pOrigFrame);
    
    if (this->getAnimation()->getRestoreOriginalFrame())
    {
        m_pOrigFrame = pSprite->displayFrame();
        m_pOrigFrame->retain();
    }
    if (m_bFirstTick) m_nNextFrame = 0;
    m_uExecutedLoops = 0;
    m_bFirstTick = false;
}
