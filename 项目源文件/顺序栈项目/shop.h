#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
模拟实现道具店购物功能
商店暂时只支持一种类型的商品
商品具备名称、价格、库存等属性

模拟玩家购买游戏道具
1.玩家选择要购买的道具
2.玩家同意交易后扣除相应的游戏币
3.对应商品库存-1
4.玩家背包中增加商品或该商品数量+1
*/

//定义结构
//1.商品结构
typedef struct _prop {
    int id;             //道具编号
    char name[50];      //名称
    int price;          //单价
    int stock;          //库存,如果在背包里就表示此商品的叠加数量
    char desc[200];     //功能描述
}Prop;


//2.背包结构
typedef struct _bag
{
    int playerId;       //玩家编号
    int count;          //当前背包中道具数量
    int max;            //当前背包的插槽总数--可以rmb购买
    Prop props[8];      //当前背包中的道具数组

}Bag;

//3.玩家结构
typedef struct _player
{
    int id;             //玩家编号
    char name[50];      //玩家名称/昵称
    char pass[50];      //密码
    Bag bag;            //玩家背包
    double gold;        //钻石
    double sysee;       //元宝数量
}Player;

int propsCount = 0;
int playersCount = 0;
Prop* props;
Player* players;
void Init();            //用来初始化游戏数据
void ShowProps();       //显示商品
void ShowPlayers();     //显示玩家信息

/*交易函数
*参数1：参与交易的玩家指针，方便修改交易后的金币数
*参数2：玩家购买的商品Id
*/
void Trade(Player* player, int propId);


int main()
{
    //1.初始化游戏数据
    Init();
    //2.打印初始化数据
    printf("\n***********交易前*************\n");
    ShowProps();
    ShowPlayers();

    Trade(&players[0], 3);
    Trade(&players[1], 4);
    printf("\n***********交易后*************\n");
    ShowProps();
    ShowPlayers();
    return 0;
}

void Trade(Player* player, int propId)
{
    int i;
    //需要判断：玩家商品的库存，玩家余额，背包空间
    Prop* tradeProp=0;//要购买的商品指针
    for (i = 0; i < propsCount; i++)
    {
        if (propId == props[i].id) {
            tradeProp = &props[i];
            break;
        }
    }
    if (tradeProp->stock <= 0)
    {

        printf("玩家没有钱了");
    }
    if (player->gold < tradeProp->price)
    {
        printf("钱不够");
        return;
    }
    if (player->bag.count >= player->bag.max && player->bag.count != 0)
    {
        printf("背包已满,交易失败！\n");
        return;
    }
    //满足交易条件，执行交易操作
    //1.商品库存-1
    tradeProp->stock--;
    //2.玩家金币-商品价格
    player->gold -= tradeProp->price;
    //3.玩家道具增加
    /*判断玩家背包是否有该商品
    *没有，将该商品加到背包中
    *有，背包商品+1 */

    for (i = 0; i < player->bag.count; i++)
    {
        //要买的商品的id 跟 背包中某个商品的id相同
        if (propId == player->bag.props[i].id)
        {
            player->bag.props[i].stock++;
            break;
        }
    }
    //如果没有该商品，将该商品加到背包中
    if (i == player->bag.count)
    {
        //向背包中创建一个商品,name和desc不能直接复制，需要strcpy()
        int newIndex = player->bag.count;
        player->bag.props[newIndex].id = tradeProp->id;
        player->bag.props[newIndex].stock = 1;
        player->bag.props[newIndex].price = tradeProp->price;
        strcpy(player->bag.props[newIndex].desc, tradeProp->desc);
        strcpy(player->bag.props[newIndex].name, tradeProp->name);
        player->bag.count++;
    }
}

void Init()
{
    //1.初始化数据
    //道具初始化
    static Prop propArray[] = {
        {1,"胡桃",1000,10,"就是比小兵厉害的英雄"},
        {2,"辽宁跑男",1000,10,"就是比小兵厉害的英雄"},
        {3,"三姓家奴",1000,10,"就是比小兵厉害的英雄"},
        {4,"赑屃",1000,10,"就是比小兵厉害的英雄"},
        {5,"杀疯辣",1000,10,"就是比小兵厉害的英雄"},
        {6,"护城河",1000,10,"就是比小兵厉害的英雄"},
        {7,"招财猫猫",1000,10,"就是比小兵厉害的英雄"},
        {8,"v1龙摆尾",1000,10,"就是比小兵厉害的英雄"},
        {9,"这把算我赢",1000,10,"就是比小兵厉害的英雄"},
        {10,"刀刀姬",1000,100,"小兵"},
        {11,"小蘑菇",1000,100,"小兵"},
        {12,"笨蛋小上仙",1000,100,"小兵"},
        {13,"幼体猫猫头",1000,100,"小兵"},
        {14,"基础猫猫头",1000,100,"小兵"},
        {15,"强化猫猫头",1000,100,"小兵"},
        {16,"精英猫猫头",1000,100,"小兵"},
        {17,"终极猫猫头",1000,100,"小兵"},
    };
    propsCount = sizeof(propArray) / sizeof(Prop);//=5
    props = propArray;//设定指针指向
    //玩家初始化
    static Player playerArray[] = {
        {1,"小智","ystz",.gold = 10000,.bag.max = 8},
        {2,"柯南","ystz",.gold = 10000,.bag.max = 8},
    };
    playersCount = 2;
    players = playerArray;
}

void ShowProps()
{
    int i;
    if (props == NULL) return;
    printf("%-5s%-12s%-7s%-7s介绍\n", "编号", "名称", "单价", "库存");
    for (i = 0; i < propsCount; i++)
    {
        printf("%-5d%-12s%d\t%d\t%s\n", props[i].id, props[i].name, props[i].price, props[i].stock, props[i].desc);
    }
    printf("\n");
}

void ShowPlayers()
{
    int i, j;
    if (players == NULL) return;
    printf("编号\t%-12s钻石\n", "名称");
    for (i = 0; i < playersCount; i++)
    {
        printf("%d\t%-12s%.0lf\n", players[i].id, players[i].name, players[i].gold);
        for (j = 0; j < players[i].bag.count; j++)
        {
            printf("玩家%s购买了%s获得了%d个\n", players[i].name, players[i].bag.props[j].name, players[i].bag.props[j].stock);
        }
        printf("\n");
    }
    printf("\n");
}
