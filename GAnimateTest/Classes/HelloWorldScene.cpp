#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

#include "AnimatePacker.h"
#include "GAnimate.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    AnimatePacker::getInstance()->loadAnimations("aaa.xml");
    
    GAnimate *animate = GAnimate::create(AnimatePacker::getInstance()->getAnimate("aaa")->getAnimation(), 10);
    CCSprite *sprite = CCSprite::create("Icon.png");
    sprite->runAction(CCRepeatForever::create(animate));
    this->addChild(sprite);
    sprite->setPosition(ccp(200, 200));
    
    
    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
