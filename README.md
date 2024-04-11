# xdyunProject

# dfx学习项目  github地址 https://github.com/duanfaxin/db_protocol_restore

#### 介绍
学习方向 CPP  项目  算法

#### 软件架构
软件架构说明

服务端 


#### 前端
1. 前端页面引用服务端路由出的URL链接
2. 后端回应数据给前端
3. 前端拿到数据展示


#### 后端
1. 服务端生成的多个URL链接
2. 前端点击夹在页面中的URL链接
3. 后端接受到前端的URL请求做出回应
4. 返回数据给前端



#### Redis数据库&MySQL数据库 
1. 将本地的图片由二进制文件转成字符串
2. 将字符串存进数据库
3. 使用数据库形式 Redis + Mysql（由于对Redis数据库没有具体了解过所以要练习）
4. 存储格式
Mysql:{
    库表  字段    name    图片转成的字符串
    限制因素: mysql 对字符串的存储是否有字节要求     
    在 MySQL 中，不同的字符串类型有不同的长度限制。以下是一些常见的字符串类型及其长度限制：
    CHAR: 定长字符串，最大长度为 255 个字符。
    VARCHAR: 可变长度字符串，最大长度为 65,535 个字符。
    TEXT: 可变长度字符串，最大长度为 65,535 个字符。
    MEDIUMTEXT: 可变长度字符串，最大长度为 16,777,215 个字符。
    LONGTEXT: 可变长度字符串，最大长度为 4,294,967,295 个字符。
}
Redis:{
    key：图片name value：图片转成的字符串
}


#### 安装教程

1.  安装docker
2.  安装mysql
3.  xxxx

#### 使用说明

1.  xxxx
2.  xxxx
3.  xxxx

#### 参与贡献

1.  Fork 本仓库
2.  新建 Feat_xxx 分支
3.  提交代码
4.  新建 Pull Request


#### 内网穿透
1. 穿透工具 localtunnel
2. 使用方法 npx localtunnel --port + 端口号
3. 使用说明 https://github.com/localtunnel/localtunnel
4. 效果 产生一个公网地址可以访问