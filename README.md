# Free counter collection #

Программа умеет посчитывать количество слов в файле с учетом некоторых знаков препинания.
Так же программа позволяет посчитать 32-х битную чексумму файла по алгоритму:

```
checksum = word1 + word2 + … + wordN (word1..wordN – 32-хбитные слова, представляющие содержимое файла)
```

# Установка #

Для сборки вам нужен компилятор с поддержкой c++17.


```shell
git clone https://github.com/bobro-krab/word-checksum-counter
cd word-checksum-counter
mkdir build && cd build
cmake ..
cd ..
cmake --build build
```

# Запуск #

```shell
./build/prog -h
# or
./build/prog -f ~/test.txt -m words -v hello
# or
./build/prog -f test.txt -m checksum
```
