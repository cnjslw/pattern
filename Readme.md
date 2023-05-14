## C1 设计模式与软件开发思想
### What is ?
设计模式

    ①是一套反复使用的代码设计经验的总结
    ②是长期总结的一套高开发效率的编程方式
    ③是解决常见问题的通用解决方法
    ④是特定场景下的可重用方案

在大型软件的设计中保证了模块之间的灵活性（可扩展、低耦合）与可复用性

### 分类
1. 行为型模式：关注对象的行为，通过对象组合，描述一组对象应该如何协作来完成整体任务
2. 创建型模式：关注如何创建对象，核心思想将对象的创建和使用分离，充分解耦以解决代码难维护和难修改的问题
3. 结构型模式：关注对象之间的关系，组合对象以获得更加灵活的结构

<br>

## C2 行为模式——模板方法模式
### What is 
举例：很多事情都是由固定的步骤来完成的，例如餐馆吃饭，主要流程 —— 点餐、用餐、结账。步骤固定，可称之为模板，但是仍然有细微的差距，比如，我点淮扬菜，你点鲁菜，他点川菜；我用RMB结账，你用Dollar结账，他用微信付款。在固定的步骤下，通过多态机制在多个子类中对每个步骤的细节差异化实现，就是模板方法的目的！

<br>

## C3 创建型模型——工厂模式、原型模式、建造者模式
### 工厂模式
将创建对象的代码包装起来，实现创建对象的代码与具体的业务逻辑代码隔离

#### 简单工厂模式
定义一个工厂类，该类的成员函数可以根据不同的参数创建并返回不同的类对象，被创建的对象所属的类一般都具有相同的父类，调用者无需关心创建对象的细节


<br>

## C10 行为模式——迭代器模式
### What is
迭代器模式是一种行为设计模式， 在不暴露集合底层表现形式 （列表、 栈和树等） 的情况下遍历集合中所有的元素[2]。

### Before this
#### 单一职责原则
一个类尽量只负责单一功能，减少能够引起类变化的原因
#### 内聚与耦合
内聚：一个模块内部的各组成部分之间彼此结合的紧密程度

耦合：模块之间相互关联的程度，分为，

    ①内容耦合
    ②公共耦合
    ③外部耦合
    ④控制耦合
    ⑤标记耦合
    ⑥数据耦合
模块之间如果必须耦合，尽量使用数据耦合，少用控制耦合，限制公共耦合，避免内容耦合




<br>
<br>
<br>
<br>

## 参考资料

[1] 《C++新经典：设计模式》王健伟

[2] https://refactoringguru.cn/design-patterns

<br>

*说明：笔记以《C++新经典：设计模式》为主线，所有未标记引用部分，均摘自或者概括自此书中的内容，所有代码也均为书中示例，无原创，仅供本人学习使用*。