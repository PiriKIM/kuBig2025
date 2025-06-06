import asyncio
import time

async def hello(value):
    print(f"hello world{value}!")
    await asyncio.sleep(5.0)

def hello2():
    print("hello world!")
    time.sleep(5)


async def main():
    # for _ in range(3):
    #     await hello() # 동기

    # tasks = [hello(), hello(), hello()]
    # await asyncio.gather(*tasks) # 비동기

    # await hello()

    # tasks = [asyncio.create_task(hello()) for _ in range(3)]
    # for task in tasks:
    #     await task

    t1 = asyncio.create_task(hello(1))
    t2 = asyncio.create_task(hello(2))
    t3 = asyncio.create_task(hello(3))
    await t1
    await t2
    await t3

    print("main 함수의 끝")

if __name__ == "__main__":
    asyncio.run(main())
