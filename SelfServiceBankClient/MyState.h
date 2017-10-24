#pragma once
/*申请状态类
Dealing,//处理中
Verify,//待审核
Dealed,//已处理
Invalid,//已失效
*/
class CApplyState {

};


class CApplyDealingState : public CApplyState {

};


class CApplyVerityState : public CApplyState{

};


class CApplyDealedState : public CApplyState {

};


class CApplyInvalidState : public CApplyState {

};