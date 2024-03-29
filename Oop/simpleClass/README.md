# <center>Простой класс<center>

## Геометрическая фигура

![shape](/out/puml/shape/Shape.png)

#### Используемые классы:
  - Point
     
     Поля:
     
     1. X - точка на оси x
     2. Y - точка на оси y
    

     Методы:

     1. Point(double x, double y) - конструктор для создания точки
     2. display() - метод для вывода точки на консоль
   
   - Shape
     
     Поля:

     1. count() - количество точек, из которых состоит фигура
     2. points() - массив точек, из которых состоит фигура
      
      Методы:

      1. Shape() - конструктор по умолчанию, создает пустую фигуру
      2. addPoint(double x, double y) - добавить точку в фигуру c заданными координатам
      3. deletePoint(int index) - удалить точку по заданному индексу, в случае ее отсутствия ничего не происходит
      4. popPoint() - удалить последнюю добавленную точку
      5. displayPoints() - вывести на коносоль координаты всех точек из которых состоит фигура
      6. getCount() - возвращает количество точек из которых состоит фигура
      7. getArea() - возвращает площадь фигуры
            
            Для нахождения площади используется [формула гауса](https://ru.wikipedia.org/wiki/%D0%A4%D0%BE%D1%80%D0%BC%D1%83%D0%BB%D0%B0_%D0%BF%D0%BB%D0%BE%D1%89%D0%B0%D0%B4%D0%B8_%D0%93%D0%B0%D1%83%D1%81%D1%81%D0%B0)

      8. getPerimeter() - возвращает периметр фигуры
   

   - Пример использования:
     
     ```cpp
     Shape someShape;

     someShape.addPoint(1, 3);
     someShape.addPoint(3, 5);
     someShape.addPoint(45,5);

     std::cout << "Area: " << someShape.getArea() << std::endl;
     std::cout << "Perimeter: " << someShape.getPerimeter() << std::endl;
     ```
         Area: 42
         Perimeter: 1.5


## Дробь

![](/out/puml/fraction/Fraction.png)

- Поля:
  
     1. numerator - числитель
     2. denumerator - знаменатель
   
- Методы:
     1. SimpleFraction() - конструктор по умолчанию, создает дробь с числителем и знаменателем равным 0
     2. SimpleFraction() - конструктор с параметрами, создает дробь с заданными числителем и знаменателем
     3. get и set для числителя и знаменателя. В случае попытки поставить 0 в знаменатель, выбрасывается исключение
     4. display() : вывести дробь на консоль
     5. add(SimpleFraction) - метод для сложения дробей
     6. sub(SimpleFraction) - метод для вычитания дробей
     7. mult(SimpleFraction) - метод для умножения дробей
     8. div(SimpleFraction) - метод для деления дробей

- Операторы:
     1. Всеовозможные операторы сравнения и действий с дробями

- Статические методы:
     1. Статические методы для операций с дробями
   
- Пример использования:
     
     ```cpp
    SimpleFraction a1(3, 4);
    SimpleFraction a2(5,6);

    SimpleFraction a3 = a1 * a2;
    SimpleFraction a4 = a1 / a2;

    std::cout << "a1 * a2 = ";
    a3.display();

    std::cout << "\na1 / a2 = ";
    a4.display();
     ```
      a1 * a2 = 15/24
      a1 / a2 = 18/20


## Вектор

![](/out/puml/vector/Vector.png)

 ### Используемые классы:

- Point:
  
     Поля:

     1. x - точка на оси x
     2. y - точка на оси y
    
     
     Методы:

    1. Point() - конструктор по умолчанию, создает точку с координатами 0, 0
    2. Point(double x, double y) - конструктор с параметрами, создает точку с заданными координатами
    3. Гетеры для полей
     

     Операторы:

     1. Вывод на консоль
     2. Умножение точек друг на друга
     3. Проверка на равенство
   

- Vector:
  
     Поля:

     1. x - координата вектора на оси x
     2. y - координата вектора на оси Y
     
     Методы:

     1. Vector() - конструктор по умолчанию, создает вектор с координатами (0, 0)
     2. Vector(double x1, double y1, double x2, double y2) - конструктор для создания вектора по заданным координатам точек
     3. Vector(Point point1, Point point2 ) - аналогичен предыдущему конструктору
     4. Vector(double x, double y) - конструктор для создания вектора с заранее известными координатами
     5. Length() - возвращает длину вектора
     6. getAngle(Vector other) - возвращает угол между текущим и other вектором
     7. гетеры и сетеры для координат
     

     Операторы:

     1.  Операторы сложения и вычитания векторов, а так же вывод на консоль
     2.  Перегруженные операторы умножения на число и вектор
     

     Пример использования:

     ```cpp
     Vector vector1(1, 5);
     Vector vector2(7, 15);

     std::cout << "Vector 1 length: " << vector1.length() << std::endl;
     std::cout << "vector1 + vector2 = " <<vector1 + vector2 << std::endl;
     ```
      Vector 1 length: 5.09902
      vector1 + vector2 = x: 8 y: 20
       
## Время

![](/out/puml/time/Time.png)

- Поля:
     
     1. Секунды, минуты и часы соответсвенно

- Методы:
  
     1. Time() - конструктор по умолчанию, задает всем переменным 0
     2. Time(double hours, double minutes, double seconds) - Конструктор для создания времени с заданными параметрами
     3. гетеры и сетеры для полей
     4. getAllSeconds() - возвращает время конвертированное в секунды
     5. Convert to ... - конвертирует время в заданную единицу измерения
     6. GetString() - возвращает строку в формате "hours:minutes:seconds"
     7. add ... () - добавить времени к заданной единице измерения

- Операторы:
     
     1. Сложение, вычитание, проверка на равенство и вывод на консоль

- Пример использования:
     
     ```cpp
     Time time1(23,445,56);
     Time time2(11, 56, 11);

     std::cout << "time1 - time2 = " <<time1 - time2 << std::endl;
     std::cout << "time1: " << time1 << std::endl;
     std::cout << "time1 in seconds: " << time1.getAllSeconds() << std::endl;
     ```
      time1 - time2 = 12:389:45
      time1: 23:445:56
      time1 in seconds: 109556
          

