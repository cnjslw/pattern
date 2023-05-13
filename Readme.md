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

## C2 行为模式——模板方法模式
### What is 
举例：很多事情都是由固定的步骤来完成的，例如餐馆吃饭，主要流程 —— 点餐、用餐、结账。步骤固定，可称之为模板，但是仍然有细微的差距，比如，我点淮扬菜，你点鲁菜，他点川菜；我用RMB结账，你用Dollar结账，他用微信付款。在固定的步骤下，通过多态机制在多个子类中对每个步骤的细节差异化实现，就是模板方法的目的！
