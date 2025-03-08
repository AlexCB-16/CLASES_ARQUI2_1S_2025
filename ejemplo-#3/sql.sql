CREATE DATABASE mi_base_de_datos;
USE mi_base_de_datos;

CREATE TABLE mi_tabla (
    id INT AUTO_INCREMENT PRIMARY KEY,
    txt VARCHAR(100) NOT NULL
);

DELIMITER $$
CREATE PROCEDURE obtener_ultimo_insertado()
BEGIN
    SELECT * FROM mi_tabla ORDER BY id DESC LIMIT 1;
END $$
DELIMITER ;

INSERT INTO mi_tabla (txt) VALUES ('txt1');
INSERT INTO mi_tabla (txt) VALUES ('txt2');
INSERT INTO mi_tabla (txt) VALUES ('txt3');

CALL obtener_ultimo_insertado();