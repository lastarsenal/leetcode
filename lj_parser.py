#!/bin/env python
# -*- coding: utf-8 -*-

# @Author:yixun
# @Date:2012-11-01

import lxml.html

header = "//div[@class=\"content\"]/div[@class=\"leftContent\"]/ul[@class=\"listContent\"]/li/div[@class=\"info\"]"
title_xpath = header + "/div[@class=\"title\"]/a/node()"
addr_xpath = header + "/div[@class=\"address\"]/div[@class=\"houseInfo\"]/span/following-sibling::node()"
deal_date_xpath = header + "/div[@class=\"address\"]/div[@class=\"dealDate\"]/node()"
total_price_xpath = header + "/div[@class=\"address\"]/div[@class=\"totalPrice\"]/span/node()"
position_xpath = header + "/div[@class=\"flood\"]/div[@class=\"positionInfo\"]/span/following-sibling::node()"
source_xpath = header + "/div[@class=\"flood\"]/div[@class=\"source\"]/node()"
junjia_xpath = header + "/div[@class=\"flood\"]/div[@class=\"unitPrice\"]/span/node()"
attr_xpath = header + "/div[@class=\"dealHouseInfo\"]//text()"

def parse(htmlfile):
    f = open(htmlfile, "r")
    doc = lxml.html.fromstring(f.read())
    f.close()
    pretty_html=lxml.html.tostring(doc,  pretty_print=True, encoding="utf8", method="xml")
    #print pretty_html
    apartment_titles = doc.xpath(title_xpath)
    addrs = doc.xpath(addr_xpath)
    deal_dates = doc.xpath(deal_date_xpath)
    total_prices = doc.xpath(total_price_xpath)
    positions = doc.xpath(position_xpath)
    qianyue_list = doc.xpath(source_xpath)
    junjia_list = doc.xpath(junjia_xpath)
    attr_list = doc.xpath(attr_xpath)
    print "title lens=%d, addrs lens=%d, deal_date len=%d, total_price len=%d, \
         position len=%d, qianyue len=%d, junjia_len=%d, attr_len=%d"%(len(apartment_titles), len(addrs),
         len(deal_dates), len(total_prices), len(positions), len(qianyue_list), len(junjia_list), len(attr_list))
    for i, title in enumerate(apartment_titles):
        title = title.encode("utf-8")
        items = title.split(" ")
        name = items[0]
        house_type = items[1]
        area = items[2]
        items = addrs[i].encode("utf-8").split("|")
        chaoxiang = items[0].strip()
        zhuangxiu = items[1].strip()
        dianti = items[2].strip()
        items = deal_dates[i].encode("utf-8").split(".")
        year_month = items[0] + "-" + items[1]
        date = items[2]
        total_price = total_prices[i].encode("utf-8")
        items = positions[i].encode("utf-8").split(" ")
        louceng = items[0]
        nianfen = items[1]
        qianyue = qianyue_list[i].encode("utf-8")
        junjia = junjia_list[i].encode("utf-8")
        attr = "ABSENT"
        if i < len(attr_list):
            attr = attr_list[i].encode("utf-8")
        print("%s %s %s %s %s %s %s %s %s %s %s %s %s元/平 %s")%(name, house_type, 
            area, chaoxiang, zhuangxiu, dianti, year_month, date, 
            total_price, louceng, nianfen, qianyue, junjia, attr)

if __name__ == "__main__":
    parse("data/index.html") 
