---
lang: ar
dir: rtl
title: "Put the title"
author: "Author name"
date: "Publication date"
---

<body dir="rtl" style="text-align: right">
<font size="3">

# <center style="color: yellow"> **شبکه‌های کامپیوتری** </center><br/>

## <center style="color: yellow"> **تمرین برنامه نویسی شماره ۰۳** </center><br/>

## <center> محمد جلالی : ۸۱۰۱۹۸۵۰۲  &nbsp;&nbsp;   &nbsp;&nbsp;   حسین بیاتی : ۸۱۰۱۹۸۳۶۶ </center>
## <center> </center><br/>

<hr style="border-bottom: solid 1px yellow"><br/>

### <center><strong style="color: orange; font-size: 28px;"> الگوریتم‌های مسیریابی در شبکه </strong><br/><span style="color: orange; font-size: 24px;">(Border Gateway - Distance Vector - Link State) </span></center><br/>

<ul style="list-style-type: none">
    <li>
        <h2>
            <strong style="color: yellow">
                نحوه اجرا            
            </strong>
        </h2>
            <br/>
            <h3>
                <ul>
                    <li>
                        با وارد کردن دستور <strong style="color: beige">make</strong> در پوشه <strong style="color: beige">Code</strong> پروژه، فایل اجرایی در این پوشه ساخته می‌شود
                        <br/><br/>
                        <image src="./images/make.png" style="width: 100%"/>
                    </li><br/>
                    <li>
                        با وارد کردن دستور <strong style="color: beige"> main.out/. </strong> برنامه راه اندازی شده و دستورات را می‌پذیرد.
                        سند <strong style="color: beige"> input.txt/.. </strong> حاوی دستورات مربوطه است و خروجی برنامه در سند <strong style="color: beige"> output.txt/.. </strong> ذخیره می‌شود.
                        <br/><br/>
                        <image src="./images/run.png" style="width: 100%"/>
                    </li>
                </ul><br/>
                برنامه به شکل پویا پیاده ساخته شده و محدودیتی برای شمار پیوندها نیست.
            </h3>
            <br/><hr style="border-bottom: solid 1px yellow"><br/>
    </li>
    <li>
        <h2>
            <strong style="color: yellow">
                ساختار
            </strong>
        </h2>
            <br/>
            <h3>
                کدهای برنامه در پوشه <strong style="color: beige"> code </strong> هستند و شامل سه کلاس می‌باشند:
                <br/><br/>
                <ul>
                    <li>
                        <strong style="color: beige">Command Handler:</strong> &nbsp; این کلاس وظیفه پردازش دستورات ورودی را داراست. اطلاعات متنی وارد شده در خط فرمان، به اطلاعات فهم پذیر برای دیگر بخش‌های برنامه تبدیل شده و به آن‌ها تحویل می‌شود.
                    </li><br/>
                    <li>
                        <strong style="color: beige">Topology:</strong> &nbsp; وظیفه‌ی نگهداری توپولوژی شبکه و انجام modify و delete با این کلاس است.
                    </li><br/>
                    <li>
                        <strong style="color: beige">Dvrp:</strong> &nbsp; با دریافت توپولوژی موجود الگوریتم را روی آن اجرا می‌کند.
                    </li><br/>
                    <li>
                        <strong style="color: beige">Lsrp:</strong> &nbsp; با دریافت توپولوژی موجود الگوریتم را روی آن اجرا می‌کند.
                    </li><br/>
                </ul>
            </h3>
            <hr style="border-bottom: solid 1px yellow"><br/>
    </li>
    <li>
        <h2>
            <strong style="color: yellow">
                شرح کد و عملکرد آن
            </strong>
        </h2>
            <br/>
            <h3>
                <ul>
                    <li>
                        <strong style="color: beige">کلاس Command Handler: &nbsp;</strong><br/><br/>
                        <ul>
                            <li>
                                <strong style="color: #80ced6">
                                    private
                                </strong> 
                                <ul>
                                    <li>
                                        <strong style="color: pink">
                                            ()CommandHandler
                                        </strong> &nbsp; 
                                    </li><br/>
                                    <li>
                                        <strong style="color: pink">
                                            vector<string> split(string str, char divider) <span style="color: beige"> : </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                    <li>
                                        <strong style="color: pink">
                                            ()void run <span style="color: beige"> : </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                </ul>
                            </li><br/>
                            <li>
                                <strong style="color: #80ced6">
                                    public
                                </strong> 
                                <ul>
                                    <li>
                                        <strong style="color: pink">
                                            NetworkTopology topology <span style="color: beige"> : </span> 
                                        </strong> &nbsp; 
                                    </li><br/>
                                </ul> 
                                <ul>
                                    <li>
                                        <strong style="color: pink">
                                            int number_of_nodes <span style="color: beige"> : </span> 
                                        </strong> &nbsp; 
                                    </li><br/>
                                </ul> 
                                <ul>
                                    <li>
                                        <strong style="color: pink">
                                            void init_topology(vector<string> p) <span style="color: beige"> : </span> 
                                        </strong> &nbsp; 
                                    </li><br/>
                                </ul> 
                                <ul>
                                    <li>
                                        <strong style="color: pink">
                                            int calcualte_number_of_node(vector<string> p) <span style="color: beige"> : </span> 
                                        </strong> &nbsp; 
                                    </li><br/>
                                </ul>
                            </li><br/>
                        </ul>
                    </li><br/>
                     <li>
                        <strong style="color: beige">کلاس Topology: &nbsp;</strong><br/><br/>
                        <ul>
                            <li>
                                <strong style="color: #80ced6">
                                    private
                                </strong> 
                                <ul>
                                    <li>
                                        <strong style="color: pink">
                                            NetworkTopology(int _number_of_nodes)
                                        </strong> &nbsp; 
                                    </li><br/>
                                </ul>
                                <ul>
                                    <li>
                                        <strong style="color: pink">
                                            ()NetworkTopology
                                        </strong> &nbsp; 
                                    </li><br/>
                                </ul>
                                <ul>
                                    <li>
                                        <strong style="color: pink">
                                            void add_path(int s,int d,int cost) <span style="color: beige"> : </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                </ul>
                                <ul>
                                    <li>
                                        <strong style="color: pink">
                                            ()void show <span style="color: beige"> : </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                </ul>
                                <ul>
                                    <li>
                                        <strong style="color: pink">
                                            void lsrp(int source) <span style="color: beige"> : </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                </ul>
                                <ul>
                                    <li>
                                        <strong style="color: pink">
                                            ()void lsrp <span style="color: beige"> : </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                </ul>
                                <ul>
                                    <li>
                                        <strong style="color: pink">
                                            void dvrp(int source) <span style="color: beige"> : </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                </ul>
                                <ul>
                                    <li>
                                        <strong style="color: pink">
                                            ()void dvrp <span style="color: beige"> : </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                </ul>
                                <ul>
                                    <li>
                                        <strong style="color: pink">
                                            vector<string> split(string str, char divider) <span style="color: beige"> : </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                </ul>
                                <ul>
                                    <li>
                                        <strong style="color: pink">
                                            void modify(string change) <span style="color: beige"> : </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                </ul>
                                <ul>
                                    <li>
                                        <strong style="color: pink">
                                            void remove(string change) <span style="color: beige"> : </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                </ul>
                            </li><br/>
                            <li>
                                <strong style="color: #80ced6">
                                    public
                                </strong> 
                                <ul>
                                    <li>
                                        <strong style="color: pink">
                                            vector<vector<int>> adjacencyMatrix <span style="color: beige"> : </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                    <li>
                                        <strong style="color: pink">
                                            int number_of_nodes <span style="color: beige"> : </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                    <li>
                                        <strong style="color: pink">
                                            LSRPProtocol lsrp_protocol <span style="color: beige"> : </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                    <li>
                                        <strong style="color: pink">
                                            DVRPProtocol dvrp_protocol <span style="color: beige"> : </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                    <li>
                                        <strong style="color: pink">
                                            ()vector<vector<int>> get_graph <span style="color: beige"> : </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                </ul>
                            </li><br/>
                        </ul>
                    </li><br/>
                     <li>
                        <strong style="color: beige">کلاس Dvrp: &nbsp;</strong><br/><br/>
                        <ul>
                            <li>
                                <strong style="color: #80ced6">
                                    private
                                </strong> 
                                <ul>
                                    <li>
                                        <strong style="color: pink">
                                            ()DVRPProtocol
                                        </strong> &nbsp; 
                                    </li><br/>
                                    <li>
                                        <strong style="color: pink">
                                            void apply_BellmanFord(vector<vector<int>> graph, int V, int E, int src)
                                        </strong> &nbsp; 
                                    </li><br/>
                                </ul>
                            </li><br/>
                            <li>
                                <strong style="color: #80ced6">
                                    public
                                </strong> 
                                <ul>
                                    <li>
                                        <strong style="color: pink">
                                            void print_info(int src, vector<int> parent, int V, int dis[])
                                        </strong> &nbsp; 
                                    </li><br/>
                                </ul>
                            </li><br/>
                        </ul>
                    </li><br/>
                     <li>
                        <strong style="color: beige">کلاس Lsrp: &nbsp;</strong><br/><br/>
                        <ul>
                            <li>
                                <strong style="color: #80ced6">
                                    private
                                </strong> 
                                <ul>
                                    <li>
                                        <strong style="color: pink">
                                            ()LSRPProtocol
                                        </strong> &nbsp; 
                                    </li><br/>
                                    <li>
                                        <strong style="color: pink">
                                            void perform_lsrp(vector<vector<int>> graph, int src)
                                        </strong> &nbsp; 
                                    </li><br/>
                                </ul>
                            </li><br/>
                            <li>
                                <strong style="color: #80ced6">
                                    public
                                </strong> 
                                <ul>
                                    <li>
                                        <strong style="color: pink">
                                            int minDistance(vector<int> dist, vector<bool> sptSet) <span style="color: beige"> : </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                    <li>
                                        <strong style="color: pink">
                                            void printSolution(vector<int> dist, vector<int> parent, int src) <span style="color: beige"> : </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                    <li>
                                        <strong style="color: pink">
                                            void print_iter(vector<int> dis) <span style="color: beige"> : </span>
                                        </strong> &nbsp; 
                                    </li><br/>
                                </ul>
                            </li><br/>
                        </ul>
                    </li><br/>
                </ul>
            </h3>
            <hr style="border-bottom: solid 1px yellow"><br/>
    </li>
     <li>
        <h2>
            <strong style="color: yellow">
                تحلیل نتایج
            </strong>
        </h2>
            <br/>
            <h3>
                نتیجه اجرای دو الگوریتم مسیریابی گفته شده بر روی توپولوژی داده شده کنار فایل‌های ارسال موجود است که حال به بررسی آنها می‌پردازیم.<br/>
                زمان اندازه گیری شده بی در نظر گیری زمان عملیات I/O بوده و پس از پایان الگوریتم به ازای هر گره است.<br/>
                با توجه به اینکه می‌دانیم الگوریتم <strong style="color: beige"> Dijkstra</strong> عملکرد بهتری از الگوریتم <strong style="color: beige">Bellman-Ford</strong> دارد، باید توقع زمان اجرای کمتری برای این الگوریتم داشته باشیم و این در نتایج مشاهده شدنیست. البته پروتوکول مسیریابی Link-State می‌توانست عملکرد بهتری نیز داشته باشد که در این پیاده سازی از آن صرف نظر شده است.(کدهای روش دیگر موجود است و در صورت نیاز می‌توان با روش دیگر آن‌ها را اجرا نمود)<br/>
                الگوریتم <strong style="color: beige">Bellman-Ford</strong> امکان تشخیص یال با وزن منفی را نیز دارد و در حالت کلی <strong style="color: beige">جامع‌تر</strong> است. برای همین کمی مرتبه زمانی بیشتری از الگوریتم <strong style="color: beige">Dijkstra</strong> دارد.
                <br/><br/>
            </h3>
    </li>
</ul>