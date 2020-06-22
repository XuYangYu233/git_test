import requests
jianlist=['C','Cs','D',"Ds","E","F","Fs","G","Gs","A","As","B"]
jielist=[str(x) for x in range(7)]
for jian in jianlist:
    for jie in jielist:
        url = "https://cdn.jsdelivr.net/gh/warpprism/cdn@latest/autopiano/static/samples/bright_piano/"+jian+jie+".mp3"
        path = "D://Study//Python_work//piano//"+jian+jie+".mp3"
        headers = {
            "User-Agent":"Mozilla/5.0 (Windows NT 6.3; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/76.0.3809.132 Safari/537.36"
        }
        respones = requests.get(url,headers=headers)
        with open(path,mode="wb") as f:
            f.write(respones.content)
        print(path+" done")

print("end")