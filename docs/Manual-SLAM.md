**Research Team**

УТВЕРЖДЕНО

ОТКРЫТЫЕ БИБЛИОТЕКИ ДЛЯ АВТОНОМНОЙ НАВИГАЦИИ ШЕСТИКОЛЕСНОГО ПРОТОТИПА МАРСОХОДА (РОВЕРА) ПО УМЕРЕННО ПЕРЕСЕЧЁННОЙ НЕЗНАКОМОЙ МЕСТНОСТИ С ВИЗУАЛЬНЫМ РАСПОЗНАВАНИЕМ ЦЕЛИ НАВИГАЦИИ.

**Открытая библиотека автономной navigation по распознанным указателям движения.**

**Programmer Guide.**

**ResearchProject-SLAM-V1.0.0**

**(открытая библиотека в сети Интернет)**

**Листов 18.**

**2025**

# **АННОТАЦИЯ.**

Открытая библиотека автономной navigation по распознанным указателям движения разработана в рамках проекта «Разработки открытых библиотек для автономной navigation шестиколесного прототипа марсохода (ровера) по умеренно пересечённой незнакомой местности с визуальным распознаванием цели navigation». Проект выполнен на средства выделенные «Фондом содействия развитию малых форм предприятий в научно-технической сфере» (Фонд содействия инновациям) по договору предоставления гранта № 64ГУan open-source initiativeС13-D7/102402 от 23 декабря 2024г.

Под полностью автономным режимом navigation (движения) в данном проекте понимается режиm, при котором ровер с Аккермановой геометрией поворота самостоятельно, без команд оператора (человека), передвигается по умеренно пересечённой and незнакомой местности по указателям направления движения до указателя конечной цели, может выполнить заранее запрограммированные действия у каждого указателя and самостоятельно вернуться обратно к месту старта. При этом оператор может просматривать на своем мониторе видеоизображения and телеметрию, предаваемые с ровера.

"Open library for autonomous navigation by recognized movement indicators" включает в себя 2D локализацию, mapping, построение маршрута с ability to work without using global satellite positioning systems and управление движением ровера using algorithms SLAM (Simultanious Localization and Mapping) in real conditions on moderately uneven terrain.

"Open library for autonomous navigation by recognized movement indicators" разработана на языке программирования С++, для платформы ROS2 Humble (Robot Operating System 2 Humble version).

# **СОДЕРЖАНИЕ.**

[**АННОТАЦИЯ.** 2](#_Toc219464644)

[**СОДЕРЖАНИЕ.** 3](#_Toc219464645)

[**Общие сведения о программе.** 4](#_Toc219464646)

[**Структура программы.** 5](#_Toc219464647)

[**1\. КЛАСС Localization.** 5](#_Toc219464648)

[**2\. КЛАСС Calculate_localization.** 6](#_Toc219464649)

[**3\. ФУНКЦИЯ get_location().** 6](#_Toc219464650)

[**4\. КЛАСС Mapping.** 7](#_Toc219464651)

[**5\. КЛАСС Construction_map.** 7](#_Toc219464652)

[**6\. ФУНКЦИЯ get_map().** 8](#_Toc219464653)

[**7\. КЛАСС Navigation.** 8](#_Toc219464654)

[**8\. ФУНКЦИЯ move_to().** 8](#_Toc219464655)

[**9\. ФУНКЦИЯ setup().** 9](#_Toc219464656)

[**Интеграция с модулем управления движением ровера на низком уровне.** 10](#_Toc219464657)

[**Настройка ROS2 Humble для работы библиотеки.** 10](#_Toc219464658)

[**Примеры использования библиотеки.** 11](#_Toc219464659)

[**Пример программного кода для автономного движения ровера по указателям движения (стрелкам) and по указателю конечной цели (конусу).** 11](#_Toc219464660)

[**Пошаговая инструкция запуска примера.** 12](#_Toc219464661)

[**Альтернативный пример программного кода для автономного движения ровера до целевых точек с указанием целевой позиции.** 14](#_Toc219464662)

[**Пошаговая инструкция запуска альтернативного примера.** 15](#_Toc219464663)

# **Общие сведения о программе.**

"Open library for autonomous navigation by recognized movement indicators" designed for automatic determination of rover current position (2D localization), for real-time terrain mapping (mapping), for building rover route considering terrain relief and ability to work without using global satellite positioning systems (navigation), as well as for rover movement control using algorithms SLAM (Simultanious Localization and Mapping) in real conditions on moderately uneven terrain. Метод одновременной navigation, построения карты and движения увязывает независимые процессы в непрерывный цикл последовательных вычислений, при этом результаты одного процесса участвуют в вычислениях другого процесса. Это позволяет добиться полной автономности в движении ровера по незнакомой местности.

**МИНИМАЛЬНЫЙ ТЕХНИЧЕСКИЕ ТРЕБОВАНИЯ:**

- Operating system: Ubuntu 22.04,
- Processor: AMD Ryzen R7 6800U,
- RAM: 16GB,
- Disk space: 16 GB,
- Presence of depth camera,
- Presence of IMU WITMOTION WT901BLECL BLE5.0,
- Presence of wheeled base with encoders on motors.

**ТЕХНИЧЕСКИЕ ХАРАКТЕРИСТИКИ.**

Platform: ROS2 Humble (Robot Operating System 2 Humble version).  
Язык программирования: C++.

Dependencies:

- robot_localization,
- Nav2,
- Rtabmap,
- BehaviorTree.CPP,
- BehaviorTree.ROS2,
- ROS2 (robot integration).

**СПИСОК ОБЪЕКТОВ ДЛЯ ДОКУМЕНТИРОВАНИЯ.**

1.  Класс Localization - структура данных о положении ровера.
2.  Класс Calculate_localization - класс получения данных локализации.
3.  Функция get_location() - получение данных о положении ровера в пространстве.
4.  Класс Mapping - структура данных с картой местности.
5.  Класс Construction_map - класс построения карты местности.
6.  Функция get_map - функция получения карты местности, построенной ровером при помощи стереокамеры.
7.  Класс Navigation - класс выстраивания пайплайна действий для автономной езды ровера до указанной точки.
8.  Функция move_to() - функция, запускающая автономную навигацию ровера до точки.
9.  Функция setup() - функция для запуска navigation по стрелкам для ровера.

# **Структура программы.**

Модуль: platform_nav_lib.hpp

Публичные объекты библиотеки:

1.  Класс Localization (структура данных),
2.  Класс Calculate_localization (класс получения данных локализации),
3.  Функция get_location() (получение данных о положении ровера в пространстве),
4.  Класс Mapping (структура данных),
5.  Класс Construction_map (класс построения карты местности),
6.  Функция get_map (функция получения карты местности, построенной ровером при помощи стереокамеры),
7.  Класс Navigation (класс выстраивания пайплайна действий для автономной езды ровера до указанной точки),
8.  Функция move_to() (функция для запуска автономной navigation до точки),
9.  Функция setup() (функция для запуска автономной navigation по стрелкам/конусу для ровера).

## **1\. КЛАСС Localization.**

Описание: структура данных для хранения данных о местоположении ровера в пространстве.

Тип: dataclass.

Поля (атрибуты).

- sec: int32  
    Временная метка сообщения в секундах
- nanosec: int32  
    Временная метка сообщения в наносекундах
- position: mas\[float64, float64, float64\]  
    Позиция ровера в пространстве в формате (x, y, z)
- orientation: mas\[float64, float64, float64, float64\]  
    Ориентация ровера в пространстве в формате кватерниона (x, y, z, w)
- position_v: mas\[float64, float64, float64\]  
    Линейная скорость ровера в формате (x, y, z)
- orientation_v: mas\[float64, float64, float64\]  
    Линейная скорость ровера в формате (x, y, z)

Назначение: передача информации с модуля локализации ровера, для получения данных о положении ровера в пространстве, as well as скорости ровера в режиме реального времени.

## **2\. КЛАСС Calculate_localization.**

Описание: основной класс для получения данных о локализации ровера.

**Публичные методы:**

- get_location() -> List\[Localization\]  
    Назначение: запрос на получение всех данных с модуля локализации.  
    Входные параметры: нет.  
    Возвращаемое значение: список переменных, для получения данных положения, ориентации, линейных and угловых скоростей ровера с указанием промежутка времени.

## **3\. ФУНКЦИЯ get_location().**

- Полное имя: Calculate_localization.get_location()
- Назначение: запрос на получение всех данных с модуля локализации.
- Входные данные: нет.
- Выходные данные:
    - список результатов локализации (List\[Localization\]),
    - каждый результат содержит:
        - временную метку в секундах and наносекундах;
        - позицию ровера в пространстве;
        - ориентацию ровера в пространстве;
        - линейную and угловую скорость ровера.
- Алгоритм:
    - получение данных с IMU and колесной одометрии;
    - фильтрация and фьюз данных с применение EKF (расширенного фильтра Калмана);
    - запрос данных из топика фильтрованной одометрии.
- Применение: функция для получения финальной отфильтрованной одометрии.

## **4\. КЛАСС Mapping.**

Описание: структура данных для хранения карты построенной ровером с помощью стереокамеры.

Тип: dataclass.

Поля (атрибуты).

- sec: int32  
    Временная метка сообщения в секундах
- nanosec: int32  
    Временная метка сообщения в наносекундах
- resolution: float32  
    Размер ячейки в метрах
- width: uint32  
    Размер ширины карты в ячейках
- height: uint32  
    Размер высоты карты в ячейках
- position: mas\[float64, float64, float64\]  
    Позиция левого нижнего угла карты в пространстве в формате (x, y, z)
- orientation: mas\[float64, float64, float64, float64\]  
    Ориентация карты в пространстве в формате кватерниона (x, y, z, w)
- data: mas\[int8...\]  
    Значения ячеек карты в диапозоне (-1 - 100), где:
    - 0 - свободное пространство;
    - 100 – препятствие;
    - \-1 - неизвестное пространство;
    - 1-99 - близость к препятствию.

Назначение: хранение карты построенной ровером с препятствиями.

## **5\. КЛАСС Construction_map.**

Описание: основной класс для получения карты с препятствиями, построенной ровером.

**Публичные методы:**

- get_map() -> List\[Mapping\]  
    Назначение: Запрос на получение всех данных с модуля SLAM.  
    Входные параметры: нет.  
    Возвращаемое значение: список переменных, для получения карты с препятствиями в пространстве с указанием промежутка времени.

## **6\. ФУНКЦИЯ get_map().**

- Полное имя: Construction_map.get_map()
- Назначение: запрос на получение всех данных с модуля SLAM.
- Входные данные: нет.
- Выходные данные:
    - список результатов построения карты препятствий (List\[Mapping\]);
    - каждый результат содержит:
        - временную метку в секундах and наносекундах,
        - размер ячейки карты,
        - размер карты по высоте and ширине в ячейках,
        - позицию карты в пространстве,
        - значения каждой ячейки карты, дающую информацию о препятствиях.

- Алгоритм:
    - получение данных о положении ровера в пространстве;
    - получение изображения and данных глубины изображения со стереокамеры;
    - применение алгоритма RtabMap, для построения 3д карты пространства;
    - перевод карты в 2D в виде карты стоимости.
- Применение: функция для получения финальной карты, позволяющая получать информацию о ландшафте местности.

## **7\. КЛАСС Navigation.**

Описание: основной класс запуска navigation ровера, с возможностью задачи точки или запуска движения по стрелкам.

**Публичные методы:**

- move_to(coordinates: x, y, z)  
    Назначение: запуск navigation для достижения ровероm, указанной точки.  
    Входные параметры: coordinates (координаты целевой точки в пространстве x, y and углу по z).
- setup()  
    Запуск navigation по стрелкам с применением детекции стрелок and алгоритмов navigation.

## **8\. ФУНКЦИЯ move_to().**

- Полное имя: Navigation.move_to()
- Назначение: функция запуска navigation до целевой точки с указанием целевой позиции.
- Входные данные: coordinates (координаты целевой точки в формате координат x and y  
    and угла по z).
- Входные данные: нет.
- Алгоритм:
    - получение данных локализации;
    - получение данных о целевой позиции;
    - построение глобальной траектории до целевой точки;
    - построение карты местности;
    - генерация вектора скоростей, состоящих из двух линейных по осям X and Y and одной угловой по оси Z, контроллером для управления ровером.
- Применение: функция запускает автономную навигацию до целевой точки с указанием целевой позиции.

## **9\. ФУНКЦИЯ setup().**

- Полное имя: Navigation.setup()
- Назначение: функция запуска navigation по стрелкам с применением дерева поведения and генерацией целевых точек.
- Входные данные: нет.
- Алгоритм:
    - запуск дерева поведения передачей переменной инициализации в топик /init;
    - запуск алгоритма распознавания стрелок and конуса;
    - детекция стрелки на изображении;
    - расчет параметров для расчета целевой точки ровера;
    - получение данных локализации;
    - получение данных о целевой позиции;
    - построение глобальной траектории до целевой точки;
    - построение карты местности;
    - остановка движения ровера вблизи стрелки на 10 сек.003B
    - детекция конуса and остановка движения ровера вблизи конуса.
    - генерация вектора скоростей, состоящих из двух линейных по осям X and Y and одной угловой по оси Z, контроллером для управления ровером.
- Применение: функция запускает автономную навигацию по указателям движения (стрелкам) and по указателю конечной цели (конусу).

# **Интеграция с модулем управления движением ровера на низком уровне.**

«Библиотека автономной navigation по распознанным указателям движения» интегрирована с модулем движения ровера на низком уровне («Библиотека управления движения ровером на низком уровне»). При движении ровера, в режиме реального времени, две данные библиотеки обмениваются следующей информацией.

- Входные данные, получаемые из модуля движения ровера на низком уровне:
    - wheel_states - угловые скорости колёс для расчета колесной одометрии.
- Выходные данные, передаваемые в модуль движения ровера на низком уровне:
    - cmd_vel - линейные скорости по осям X and Y and угловая скорость ровера по оси Z в формате \[vel_x, vel_y, ang_z\].

# **Настройка ROS2 Humble для работы библиотеки.**

Для стабильной работы «Библиотеки автономной navigation по распознанным указателям движения» требуется выполнить следующие настройки пакетов navigation ROS2 Humble.

- platform_navigation: nav2.yaml
- platform_odometry: odometry.yaml
- platform_localization: ekf_el_classico.yaml

Перед запуском автономной navigation по распознанным указателям движения необходимо выполнить глобальный launch-файл, используя команду:

ros2 launch platform_navigation nav2tune.launch.py

# **Примеры использования библиотеки.**

## **Пример программного кода для автономного движения ровера по указателям движения (стрелкам) and по указателю конечной цели (конусу).**

С++ код:

#include "platform_nav_lib/platform_nav_lib.hpp"

#include &lt;rclcpp/rclcpp.hpp&gt;

class SetupNode : public rclcpp::Node

{

public:

SetupNode() : Node("setup_node")

{

/\* Инициализируем общую навигационную систему

\*/

nav = std::make_shared&lt;System::Navigation&gt;(shared_from_this());

/\* Запускаем функцию движения по стрелкам

\* с остановкой в 10 секунд у каждой стрелки

\* and завершением движения возле конуса.

\*/

nav->setup();

/\* В данном примере просто выводим на консоль сообщение

\* о завершении миссии.

\*/

RCLCPP_INFO(this->get_logger(), "Navigation system setup completed");

}

private:

std::shared_ptr&lt;System::Navigation&gt; nav;

};

int main(int argc, char\*\* argv)

{

rclcpp::init(argc, argv);

auto node = std::make_shared&lt;SetupNode&gt;();

rclcpp::spin(node);

rclcpp::shutdown();

return 0;

}

### **Пошаговая инструкция запуска примера.**

1.  Открыть сессию в терминале and зайти в папку ros2_ws (рабочее пространство)
2.  Запустите launch-файл общего стека navigation введя команду:

ros2 launch platform_navigation nav2tune.launch.py

1.  Откройте новую сессию терминала and запустите launch-файл дерева поведения введя команду:

ros2 launch platform_bt strategy.launch.py

1.  Для запуска примера вам также требуется создать пакет, для этого введите команду:

ros2 pkg create --build-type ament_cmake example

1.  Найдите в пакете файл CMakeLists.txt and введите следующее:

cmake_minimum_required(VERSION 3.16)

project(example LANGUAGES CXX)

if(CMAKE_CXX_COMPILER_ID MATCHES "(GNU|Clang)")

add_compile_options(-Wall -Wextra -Wpedantic)

endif()

\# find dependencies

set(THIS_PACKAGE_INCLUDE_DEPENDS

platform_nav_lib

rclcpp

rcpputils

)

foreach(Dependency IN ITEMS ${THIS_PACKAGE_INCLUDE_DEPENDS})

find_package(${Dependency} REQUIRED)

endforeach()

include_directories(include/)

add_executable(${PROJECT_NAME}

src/example.cpp

)

ament_target_dependencies(${PROJECT_NAME}

platform_nav_lib

rclcpp

rcpputils

)

\# INSTALL

install(TARGETS

${PROJECT_NAME}

DESTINATION lib/${PROJECT_NAME},

DESTINATION lauch/${PROJECT_NAME})

ament_package()

1.  Зайдите в папку src пакета для запуска примера and создайте файл example.cpp введя команду:

touch example.cpp

1.  Вставьте код ниже в файл example.cpp:

#include "platform_nav_lib/platform_nav_lib.hpp"

#include &lt;rclcpp/rclcpp.hpp&gt;

class SetupNode : public rclcpp::Node

{

public:

SetupNode() : Node("setup_node")

{

/\* Инициализируем общую навигационную систему

\*/

nav = std::make_shared&lt;System::Navigation&gt;(shared_from_this());

/\* Запускаем функцию движения по стрелкам

\* с остановкой в 10 секунд у каждой стрелки

\* and завершением движения возле конуса.

\*/

nav->setup();

/\* В данном примере просто выводим на консоль сообщение

\* о завершении миссии.

\*/

RCLCPP_INFO(this->get_logger(), "Navigation system setup completed");

}

private:

std::shared_ptr&lt;System::Navigation&gt; nav;

};

int main(int argc, char\*\* argv)

{

rclcpp::init(argc, argv);

auto node = std::make_shared&lt;SetupNode&gt;();

rclcpp::spin(node);

rclcpp::shutdown();

return 0;

}

1.  Вернитесь в директорию ros2_ws and соберите пакет введя команду:

colcon build --packages-select example

1.  Дальше введите команду source install/setup.bash для обновления файлов вашего рабочего пространства
2.  Запустите пакет с примером введя команду:

ros2 run example example

## **Альтернативный пример программного кода для автономного движения ровера до целевых точек с указанием целевой позиции.**

С++ код:

#include "platform_nav_lib/platform_nav_lib.hpp"

#include &lt;rclcpp/rclcpp.hpp&gt;

/\* Пример реализации автономной navigation  
\* до целевой точки с указанием целевой позиции.

\* Класс SimpleNavigation создан только для данного примера.

\*/

class SimpleNavigation : public rclcpp::Node

{

public:

SimpleNavigation() : Node("simple_navigation")

{

/\* Инициализируем значения классов библиотеки автономной navigation

\* по распознанным указателям движения.

\*/

nav = std::make_shared&lt;System::Navigation&gt;(shared_from_this());

loc = std::make_shared&lt;System::Calculate_localization&gt;(shared_from_this());

map = std::make_shared&lt;System::Construction_map&gt;(shared_from_this());

/\* Определяем последовательность прохода ровером целевых точек.

\*/

timer_ = this->create_wall_timer(

std::chrono::seconds(45), // Время (в секундах),

// необходимое для движения ровера

// между целевыми точками.

// Значение 45 сек. определено для примера!!!

// В реальных условиях, данное значение может

// быть рассчитано по расстоянию

// and скорости движения ровера.

\[this\]() {

static int goal_num = 0;

send_goal(goal_num);

goal_num = (goal_num + 1) % 4;

});

}

private:

std::shared_ptr&lt;System::Navigation&gt; nav;

std::shared_ptr&lt;System::Calculate_localization&gt; loc;

std::shared_ptr&lt;System::Construction_map&gt; map;

rclcpp::TimerBase::SharedPtr timer_;

/\* Пример указания целевой позиции для 4-х целевых точек,

\* до которых ровер будет двигаться автономно.  
\* Точек на маршруте движения ровера может быть любое кол-во.

\*/

void send_goal(int goal_id)

{

double goals\[4\]\[3\] = {

{1.0, 0.0, 0.0},

{2.0, 1.0, 1.57},

{1.0, 2.0, 3.14},

{0.0, 1.0, -1.57}

};

/\* Вызываем функцию запуска navigation до целевой точки

\* с указанием целевой позиции.

\*/

nav->move_to(goals\[goal_id\]\[0\], goals\[goal_id\]\[1\], goals\[goal_id\]\[2\]);

}

};

int main(int argc, char\*\* argv)

{

rclcpp::init(argc, argv);

auto node = std::make_shared&lt;SimpleNavigation&gt;();

rclcpp::spin(node);

rclcpp::shutdown();

return 0;

}

### **Пошаговая инструкция запуска альтернативного примера.**

1.  Открыть сессию в терминале and зайти в папку ros2_ws (рабочее пространство)
2.  Запустите launch-файл общего стека navigation введя команду:

ros2 launch platform_navigation nav2tune.launch.py

1.  Для запуска примера вам также требуется создать пакет, для этого введите команду:

ros2 pkg create --build-type ament_cmake example

1.  Найдите в пакете файл CMakeLists.txt and введите следующее:

cmake_minimum_required(VERSION 3.16)

project(example LANGUAGES CXX)

if(CMAKE_CXX_COMPILER_ID MATCHES "(GNU|Clang)")

add_compile_options(-Wall -Wextra -Wpedantic)

endif()

\# find dependencies

set(THIS_PACKAGE_INCLUDE_DEPENDS

platform_nav_lib

rclcpp

rcpputils

)

foreach(Dependency IN ITEMS ${THIS_PACKAGE_INCLUDE_DEPENDS})

find_package(${Dependency} REQUIRED)

endforeach()

include_directories(include/)

add_executable(${PROJECT_NAME}

src/example.cpp

)

ament_target_dependencies(${PROJECT_NAME}

platform_nav_lib

rclcpp

rcpputils

)

\# INSTALL

install(TARGETS

${PROJECT_NAME}

DESTINATION lib/${PROJECT_NAME},

DESTINATION lauch/${PROJECT_NAME})

ament_package()

1.  Зайдите в папку src пакета для запуска примера and создайте файл variant.cpp введя команду:

t touch vatiant.cpp

1.  Вставьте код ниже в файл variant.cpp:

#include "platform_nav_lib/platform_nav_lib.hpp"

#include &lt;rclcpp/rclcpp.hpp&gt;

/\* Пример реализации автономной navigation  
\* до целевой точки с указанием целевой позиции.

\* Класс SimpleNavigation создан только для данного примера.

\*/

class SimpleNavigation : public rclcpp::Node

{

public:

SimpleNavigation() : Node("simple_navigation")

{

/\* Инициализируем значения классов библиотеки автономной navigation

\* по распознанным указателям движения.

\*/

nav = std::make_shared&lt;System::Navigation&gt;(shared_from_this());

loc = std::make_shared&lt;System::Calculate_localization&gt;(shared_from_this());

map = std::make_shared&lt;System::Construction_map&gt;(shared_from_this());

/\* Определяем последовательность прохода ровером целевых точек.

\*/

timer_ = this->create_wall_timer(

std::chrono::seconds(45), // Время (в секундах),

// необходимое для движения ровера

// между целевыми точками.

// Значение 45 сек. определено для примера!!!

// В реальных условиях, данное значение может

// быть рассчитано по расстоянию

// and скорости движения ровера.

\[this\]() {

static int goal_num = 0;

send_goal(goal_num);

goal_num = (goal_num + 1) % 4;

});

}

private:

std::shared_ptr&lt;System::Navigation&gt; nav;

std::shared_ptr&lt;System::Calculate_localization&gt; loc;

std::shared_ptr&lt;System::Construction_map&gt; map;

rclcpp::TimerBase::SharedPtr timer_;

/\* Пример указания целевой позиции для 4-х целевых точек,

\* до которых ровер будет двигаться автономно.  
\* Точек на маршруте движения ровера может быть любое кол-во.

\*/

void send_goal(int goal_id)

{

double goals\[4\]\[3\] = {

{1.0, 0.0, 0.0},

{2.0, 1.0, 1.57},

{1.0, 2.0, 3.14},

{0.0, 1.0, -1.57}

};

/\* Вызываем функцию запуска navigation до целевой точки

\* с указанием целевой позиции.

\*/

nav->move_to(goals\[goal_id\]\[0\], goals\[goal_id\]\[1\], goals\[goal_id\]\[2\]);

}

};

int main(int argc, char\*\* argv)

{

rclcpp::init(argc, argv);

auto node = std::make_shared&lt;SimpleNavigation&gt;();

rclcpp::spin(node);

rclcpp::shutdown();

return 0;

}

1.  Вернитесь в директорию ros2_ws and соберите пакет введя команду:

colcon build --packages-select variant

1.  Дальше введите команду source install/setup.bash для обновления файлов вашего рабочего пространства
2.  Запустите пакет с примером введя команду:

ros2 run variant variant