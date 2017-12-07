//
// cocos2d
//
#ifndef __CHIPMUNKTEST_H__
#define __CHIPMUNKTEST_H__

#include "cocos2d.h"
#include "chipmunk.h"
#include "../testBasic.h"
#include "cocos-ext.h"

USING_NS_CC_EXT;

class ChipmunkTestLayer : public CCLayer
{
public:
    ChipmunkTestLayer();
    ~ChipmunkTestLayer();
    void onEnter();
    void initPhysics();
    void createResetButton();
    void reset(CCObject* sender);

    void addNewSpriteAtPosition(CCPoint p);
    void update(float dt);
    void toggleDebugCallback(CCObject* pSender);
    
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
    
//    virtual void ccTouchesBegan(CCSet* touches, CCEvent* event);
//    virtual void ccTouchesMoved(CCSet* touches, CCEvent* event);
//    virtual void ccTouchesCancelled(CCSet* touches, CCEvent* event);
    virtual void ccTouchesEnded(CCSet* touches, CCEvent* event);
    virtual void didAccelerate(CCAcceleration* pAccelerationValue);

private:
    CCTexture2D* m_pSpriteTexture; // weak ref
#if CC_ENABLE_CHIPMUNK_INTEGRATION    
    CCPhysicsDebugNode* m_pDebugLayer; // weak ref
#endif
    cpSpace* m_pSpace; // strong ref
    cpShape* m_pWalls[4];
};

class ChipmunkAccelTouchTestScene : public TestScene
{
public:
    virtual void runThisTest();
};

#endif /* __CHIPMUNKACCELTOUCHTEST_H__ */
