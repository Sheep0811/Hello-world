import time
import requests
from email import encoders
from email.header import Header
from email.mime.text import MIMEText
from email.utils import parseaddr, formataddr

# import smtplib
        
# def _format_addr(s):
#     name, addr = parseaddr(s)
#     return formataddr((Header(name, 'utf-8').encode(), addr))

# def sendmail(msg):
#     from_addr = '###'
#     password = '###'
#     to_addr = '###'
#     smtp_server = '###'
#     msg['From'] = _format_addr('python <%s>' % from_addr)
#     msg['To'] = _format_addr('ning <%s>' % to_addr)
#     msg['Subject'] = Header('页面有更新！', 'utf-8').encode()
#     server = smtplib.SMTP(smtp_server, 25)
#     ###server.set_debuglevel(1)
#     server.login(from_addr, password)
#     server.sendmail(from_addr, [to_addr], msg.as_string())
#     server.quit()

timesleep=300
maxtime=30000
print("begin!\n")
url="https://game.campus.163.com/personal"
headers={
    'Accept-Language':'zh-Hans-CN, zh-Hans; q=0.5','User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.102 Safari/537.36 Edge/18.18362'}
a=requests.get(url,headers=headers)
a.encoding = 'utf-8'
print(a.text)
time.sleep(timesleep)
count=0
while(count<maxtime):
    b=requests.get(url,headers=headers)
    print("Got it")
    if(a.text!=b.text):
        a=b
        print("update!")
        count=count+1
    else:
        print("no update...")
    time.sleep(timesleep)