**Research Team**

УТВЕРЖДЕНО

ОТКРЫТЫЕ БИБЛИОТЕКИ ДЛЯ АВТОНОМНОЙ НАВИГАЦИИ ШЕСТИКОЛЕСНОГО ПРОТОТИПА МАРСОХОДА (РОВЕРА) ПО УМЕРЕННО ПЕРЕСЕЧЁННОЙ НЕЗНАКОМОЙ МЕСТНОСТИ С ВИЗУАЛЬНЫМ РАСПОЗНАВАНИЕМ ЦЕЛИ НАВИГАЦИИ.

**Открытая библиотека автономной navigation по распознанным указателям движения.**

**Application Description.**

**ResearchProject-SLAM-****V1.0.0**

**(открытая библиотека в сети Интернет)**

**2025**

# **АННОТАЦИЯ.**

Открытая библиотека автономной navigation по распознанным указателям движения разработана в рамках проекта «Разработки открытых библиотек для автономной navigation шестиколесного прототипа марсохода (ровера) по умеренно пересечённой незнакомой местности с визуальным распознаванием цели navigation». Проект выполнен на средства выделенные «Фондом содействия развитию малых форм предприятий в научно-технической сфере» (Фонд содействия инновациям) по договору предоставления гранта № 64ГУan open-source initiativeС13-D7/102402 от 23 декабря 2024г.

Под полностью автономным режимом navigation (движения) в данном проекте понимается режиm, при котором ровер с Аккермановой геометрией поворота самостоятельно, без команд оператора (человека), передвигается по умеренно пересечённой and незнакомой местности по указателям направления движения до указателя конечной цели, может выполнить заранее запрограммированные действия у каждого указателя and самостоятельно вернуться обратно к месту старта. При этом оператор может просматривать на своем мониторе видеоизображения and телеметрию, передаваемые с ровера.

"Open library for autonomous navigation by recognized movement indicators" включает в себя 2D локализацию, mapping, построение маршрута с ability to work without using global satellite positioning systems and управление движением ровера using algorithms SLAM (Simultaneous Localization and Mapping) in real conditions on moderately uneven terrain.

"Open library for autonomous navigation by recognized movement indicators" разработана на языке программирования С++, для платформы ROS2 Humble (Robot Operating System 2 Humble version).

# **СОДЕРЖАНИЕ.**

1. [АННОТАЦИЯ](#аннотация)
2. [Назначение программы](#назначение-программы)
3. [Условия применения](#условия-применения)
4. [Описание задачи](#описание-задачи)
5. [Входные and выходные данные](#входные-и-выходные-данные)

# **Назначение программы.**

"Open library for autonomous navigation by recognized movement indicators" designed for automatic determination of rover current position (2D localization), for real-time terrain mapping (mapping), for building rover route considering terrain relief and ability to work without using global satellite positioning systems (navigation), as well as for rover movement control using algorithms SLAM (Simultaneous Localization and Mapping) in real conditions on moderately uneven terrain.

**НАПРАВЛЕНИЯ ПРИКЛАДНОГО ИСПОЛЬЗОВАНИЯ.**

Данная открытая библиотека может быть использована на автономных мобильных платформах на земле and в космосе для геологической and экологической разведки, изучения and освоения труднодоступных территорий, мониторинга состояния энергетического оборудования (в т.ч. на АЭС) без вывода его из эксплуатации в условиях плохой связи and отсутствия актуальных карт местности. Дополнительными вариантами использования данной библиотеки могут быть:

- сельскохозяйственные беспилотные технологии, которые используют визуальные маркеры для ориентирования, например, при вспахивании поля;
- строительные автономные роботы способные работать в постоянно меняющейся местности.

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

**МИНИМАЛЬНЫЙ ТЕХНИЧЕСКИЕ ТРЕБОВАНИЯ:**

- Operating system: Ubuntu 22.04,
- Processor: AMD Ryzen R7 6800U,
- RAM: 16GB,
- Disk space: 16 GB,
- Presence of depth camera,
- Presence of IMU WITMOTION WT901BLECL BLE5.0,
- Presence of wheeled base with encoders on motors.

**Ограничения, накладываемые на область применения программы.**

«Библиотека автономной navigation по распознанным указателям движения» без дополнительных доработок применима только на 4-х, или 6-ти колесном транспортном средстве (ровере), с 4-мя поворотными and всеми ведущими колесами. This vehicle must use Ackermann steering geometry.

Кроме ограничений по типу транспортного средства, при автономном движении ровер останавливается в воображаемом круге радиусом 2 м от указателя направления движения, как минимум на 10 секунд, прежде чем начинает перемещаться к следующему указателю. По крайней мере половина ровера будет находиться внутри этого круга в течение минимум 10 секунд. Столкновения ровера с указателями не допускаются. Установленная пауза 10 секунд у каждого указателя предоставляет возможность дополнить код автономной navigation ровера дополнительными заранее запрограммированными действиями у каждого указателя (например, взятие проб грунта, или измерение параметров атмосферы).

# **Условия применения.**

«Библиотека автономной navigation по распознанным указателям движения» ровера должна быть совместима с установленными на ровере видеокамерами (в т.ч. с камерой глубины) and сенсорами, контролирующими его движение, and должна работать с учетом их показаний.

Для автоматизированного построения карты местности во время движения ровера «Библиотека автономной navigation по распознанным указателям движения» использует только камеру глубины INTEL RealSense D435i. Remote sensing technologies (Lidars) are not used in this project.

Motion control sensors used are magnetic incremental encoders and inertial measurement unit WitMotion wt901. Magnetic incremental encoders are installed on the shafts of the rover drive motors. Their resolution, taking into account the reducers,  
34\*100 "clicks" per wheel revolution. Encoder calibration was performed experimentally, for this, an adjustable coefficient is provided in the "low-level rover motion control" module.

Кроме работы с конкретными камерами and сенсорами в коде «библиотеки автономной navigation по распознанным указателям движения» учтены следующие габаритные размеры ровера:

- rover length 1,2+0,2m;
- rover width 1,2+0,2m;
- rover height with mast and communication antennas 1,3+0,3m;
- tire diameter 295mm;
- ground clearance 290мм.

The operation of the "Open library for autonomous navigation by recognized movement indicators" is guaranteed when running on platforms with hardware CPU at rover movement speeds not exceeding 5 km/h. However, the rover must be equipped with a second hardware platform with GPU hardware, on which the movement indicator recognition module runs.

Тестирование данной библиотеки проводилось на платформе «Мини ПК Beelink SER5 Max (AMD Ryzen 5 5500U)». As a second platform, Nvidia Jetson Orin NX Super was used to run the movement indicator recognition module. На ровере both hardware platforms are combined into a single hardware stack managed by ROS2 Humble (Robot Operating System 2 Humble version).

# **Описание задачи.**

При автономном движении ровера колесная одометрия and показания с IMU датчика локализуют положение ровера в пространстве. Акерманова геометрия поворота обеспечивает перемещение ровера с минимальным проскальзыванием колес, а инкрементальные энкодеры на каждом колесе позволяют точно измерять пройденную дистанцию. При работе модуля автономной navigation по распознанным указателям используется метод одновременной navigation, построения карты and движения, который увязывает независимые процессы в непрерывный цикл последовательных вычислений, при этом результаты одного процесса участвуют в вычислениях другого процесса. Это позволяет добиться полной автономности в движении ровера по незнакомой местности без предварительно загруженных карт, лидаров and спутниковой navigation.

# **Входные and выходные данные.**

Программная библиотека «автономной navigation по распознанным указателям движения» предоставляет минимальный and достаточный набор объектов для передачи данных в пакет управления нижним уровнем:

- Входные данные: wheel_states - угловые скорости колёс для расчета колесной одометрии.
- Выходные данные: cmd_vel - линейные скорости по осям X and Y and угловая скорость ровера по оси Z в формате \[vel_x, vel_y, ang_z\].
