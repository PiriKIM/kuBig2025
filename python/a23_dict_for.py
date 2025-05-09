def main():
    dict_a = dict()
    list_a = ["사라질까?", "흠..."]
    dict_b = {1:1, 2:2, 3:list_a}   # 정의할 때 set과 헷갈리지 않게 주의

    a = 'd'
    dict_c = {'a':100, 'b':200, 'c':300, a:400}
    
    for i in dict_c:
        print(i, dict_c[i], end=', ')
    print()

    for k, v in dict_c.items():
        print(k, v, end=', ')
    print()

    print(dict_a, dict_b, dict_c)
    dict_a.update(dict_b)
    dict_a.update(dict_c)
    print(dict_a)

    del dict_a[3]
    print(dict_a)   # dict에서만 사라짐
    print(list_a)   # 아직 살아있음
    del list_a      # list_a 사라짐

    print(dict_a.pop('d'))  # 제거와 동시에 쓰일 때
    print(dict_a)

if __name__ == "__main__":
    main()