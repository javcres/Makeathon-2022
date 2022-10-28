drop database if exists desertificacion;
create database desertificacion;
use desertificacion;

create table Sensor (
    id INT,
    provincia VARCHAR(255),
    area VARCHAR(255),
    usoTerreno VARCHAR(255),
    latitud DOUBLE,
    longitud DOUBLE,
    tasaTierraExplotada FLOAT,
    primary key (id)
);

create table Registro (
    id INT,
    fecha DATETIME, 
    temperatura DOUBLE,
    humedad DOUBLE,
    luz INT,
    riesgoDesertificacion FLOAT,
    primary key (id, fecha),
    foreign key (id) references Sensor(id)
);

insert into Sensor(id, provincia, area, usoTerreno, latitud, longitud, tasaTierraExplotada)
values
    (1, "Salamanca", "Bejar", "Alojamiento", 40.3757, -5.76141, 40),
    (2, "Salamanca", "Bejar", "Investigacion", 40.3757, -5.9435, 40),
    (3, "Valladolid", "Viana", "Agricultura", 42.00955, -4.52406, 40),
    (4, "Zamora", "Cubillos", "Ganaderia", 41.5749, -5.73942, 50);

insert into Registro(id, fecha, temperatura, humedad, luz, riesgoDesertificacion)
values
    (3, "2022-9-16 13:23:44", 23.0, 87.4, 500, 20),
    (3, "2022-9-16 14:00:00", 27.0, 70.0, 560, 40),
    (3, "2022-9-16 15:00:00", 32.0, 40.0, 800, 70),
    (4, "2022-9-16 13:23:44", 19.0, 87.4, 200, 20),
    (4, "2022-9-16 14:00:00", 18.0, 90.0, 150, 10),
    (4, "2022-9-16 15:00:00", 17.0, 95.0, 50, 5),
    (3, "2022-9-17 13:23:44", 21.0, 87.4, 500, 25),
    (3, "2022-9-17 14:00:00", 24.0, 70.0, 520, 45),
    (3, "2022-9-17 15:00:00", 33.0, 40.0, 700, 75),
    (4, "2022-9-17 13:23:44", 16.0, 47.4, 200, 25),
    (4, "2022-9-17 14:00:00", 17.0, 70.0, 150, 15),
    (4, "2022-9-17 15:00:00", 18.5, 68.0, 50, 12);    

insert into Registro(id, fecha, temperatura, humedad, luz, riesgoDesertificacion)
values
    (3, "2022-9-18 13:23:44", 20.5, 90.4, 520, 19),
    (3, "2022-9-18 14:00:00", 26.0, 69.0, 860, 22),
    (3, "2022-9-18 15:00:00", 31.5, 40.0, 880, 47),
    (4, "2022-9-18 13:23:44", 19.0, 87.4, 200, 20),
    (4, "2022-9-18 14:00:00", 18.0, 90.0, 150, 13),
    (4, "2022-9-18 15:00:00", 17.0, 95.0, 50, 5),
    (3, "2022-9-19 13:23:44", 25.0, 87.4, 510, 25),
    (3, "2022-9-19 14:00:00", 26.3, 60.0, 720, 55),
    (3, "2022-9-19 15:00:00", 33.0, 40.0, 730, 75),
    (4, "2022-9-19 13:23:44", 16.0, 47.4, 230, 25),
    (4, "2022-9-19 14:00:00", 17.0, 70.0, 180, 15),
    (4, "2022-9-19 15:00:00", 18.5, 68.0, 150, 12);
