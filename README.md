# RectMans

An online multiplayer game made with C++ and Qt 6.\
用C++和Qt做的tcp联机躲避僵尸游戏

## 示例

[B站视频演示视频](https://www.bilibili.com/video/BV1oL411h7Ms/?spm_id_from=333.999.0.0) 

<img src="https://bed.kevinwu.cc/img/rectman.webp" style="zoom:30%;" />

## 指引

游戏用QT类库TCP实现联机功能。

##### 位置同步:

原理是每帧向对方传输自己坐标

##### 镜头跟随人物:

在相互传输坐标的基础上，将自己始终固定在屏幕中间，自己移动时，只改变方向。

对方传来其坐标时，计算相对位置显示。

##### 树木伪3D：

玩家y轴坐标小于树的时，树显示于上层；
玩家y轴坐标大于树的时，玩家显示于上层；
(坐标轴轴心是左上角)

##### 僵尸功能：

对比与玩家的距离，并追踪距离最近的玩家

##### 未完成：

没有同步两个玩家的僵尸和树木，意思是两边玩家看到的僵尸和树位置是不一样的。

### 对你有帮助的话，请给个star关注下。