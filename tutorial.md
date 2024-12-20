# Учебное руководство по игре "Быки и Коровы"

## Введение
"Быки и Коровы" - это классическая логическая игра, в которой игрок должен угадать 4-значное число, загаданное компьютером. Цифры в числе не повторяются. После каждой попытки игрок получает подсказки в виде количества "быков" и "коров".

## Установка
Для запуска игры выполните следующие шаги:

1. Скомпилируйте проект:
    ```sh
    g++ -o BullsCows main.cpp
    ```

2. Запустите исполняемый файл:
    ```sh
    ./BullsCows
    ```

## Правила игры
1. Компьютер загадывает 4-значное число с неповторяющимися цифрами.
2. Игрок вводит 4-значное число с неповторяющимися цифрами.
3. Компьютер сообщает количество "быков" и "коров".
    - **Бык**: цифра есть в загаданном числе и стоит на правильной позиции.
    - **Корова**: цифра есть в загаданном числе, но стоит на неправильной позиции.
4. Игра продолжается до тех пор, пока игрок не угадает число или не исчерпает все попытки.

Разработано `nikzan`.