CREATE TABLE IF NOT EXISTS registros_temperatura (
    id INT AUTO_INCREMENT PRIMARY KEY,
    fecha_hora DATETIME NOT NULL,
    temperatura DECIMAL(5,2) NOT NULL,
    dia_semana VARCHAR(10) GENERATED ALWAYS AS (DAYNAME(fecha_hora)) STORED,
    hora_dia INT GENERATED ALWAYS AS (HOUR(fecha_hora)) STORED
);

CREATE INDEX idx_fecha_hora ON registros_temperatura(fecha_hora);
CREATE INDEX idx_dia_hora ON registros_temperatura(dia_semana, hora_dia);


-- consulta

SELECT
    LPAD(hora_dia, 2, '0') AS "HORA",
    COALESCE(ROUND(AVG(CASE WHEN dia_semana = 'Monday' THEN temperatura END), 1), '--') AS "LUNES",
    COALESCE(ROUND(AVG(CASE WHEN dia_semana = 'Tuesday' THEN temperatura END), 1), '--') AS "MARTES",
    COALESCE(ROUND(AVG(CASE WHEN dia_semana = 'Wednesday' THEN temperatura END), 1), '--') AS "MIERCOLES",
    COALESCE(ROUND(AVG(CASE WHEN dia_semana = 'Thursday' THEN temperatura END), 1), '--') AS "JUEVES",
    COALESCE(ROUND(AVG(CASE WHEN dia_semana = 'Friday' THEN temperatura END), 1), '--') AS "VIERNES",
    COALESCE(ROUND(AVG(CASE WHEN dia_semana = 'Saturday' THEN temperatura END), 1), '--') AS "SABADO",
    COALESCE(ROUND(AVG(CASE WHEN dia_semana = 'Sunday' THEN temperatura END), 1), '--') AS "DOMINGO"
FROM registros_temperatura
WHERE fecha_hora BETWEEN '2025-03-21' AND '2025-03-26'
GROUP BY hora_dia
ORDER BY hora_dia;