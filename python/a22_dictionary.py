def main():
    dict_a = dict()
    dict_b = {1:1, 2:2, 3:3}   # 정의할 때 set과 헷갈리지 않게 주의
    dict_c = {1, 2, 3}
    print(type(dict_a), type(dict_b), type(dict_c))

    a = 'e'
    dict_d = {'a':100, 'b':200, 'c':300, 'd':400, a:500}    # a정의 없이하면 name error
    print(dict_d['d'])
    print(dict_d['e'])
    dict_d['e'] = 600   # 데이터 덮어씌워짐
    print(dict_d['e'])
    dict_d['f'] = 700   # 데이터 추가됨
    print(dict_d)
    # print(dict_d['g'])      # key error
    print(dict_d.get('g'))  # 안전한 접근

if __name__ == "__main__":
    main()