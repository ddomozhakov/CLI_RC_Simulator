Цель проекта состоит в закреплении базовых знаний программирования на языке Си. 
Суть проекта заключена в моделировании интегрирующей RC-цепи.  
Интегрирующая RC-цепь сглаживает резкие перепады напряжения. 
Схема RC-цепи представлена на рисунке.

![image](misc/images/Readme_1.jpg)

Выходное напряжение $V _ { out }$ зависит от времени $t$ по закону:

$$
V _ { out } (t) = V _ { 0 } * \( 1 - \exp^\frac { - t } { RC })
$$

Программа пошагово производит симуляцию приращений заряда на конденсаторе за условный период времени.
Результат симуляции записывается в файлы. При выводе на экран данные читаются из файлов. 
График выводится в терминале (псевдографика). 

Сборка программы и запуск: 
Тестировал на Mac OS Big Sur, Ubuntu 23. 
Для запуска следует перейти в src, ввести команду make. Для компиляции требуется GCC.
Исполняемый файл доступен в папке src. 
Для удаления временных файлов ввести команду make clean. 

Работа программы:
Программа работает в интерактивном режиме. 
Нажание управляющих кнопок клавиатуры меняет параметры симуляции.
Переключение между графиками входного и выходного сигналов: 1/2.
Изменение периода входного сигнала - a/z.
Изменение емкости RC-цепи: s/x.
Изменение сопротивления RC-цепи: d/c.
Выход из программы - q. 

Если графики выводят кашу и хаос, растяните терминал на весь экран и/или увеличьте масштаб отображения символов терминала.