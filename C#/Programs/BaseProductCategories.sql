CREATE TABLE Products (
	Id INT PRIMARY KEY,
	NAME nvarchar(128) not null
);

INSERT INTO Products
VALUES
	(1, 'Examination_1'),
	(2, 'Examination_2'),

CREATE TABLE Categories (
	Id INT PRIMARY KEY,
	NAME nvarchar(128) not null
);

INSERT INTO Categories
VALUES
	(1, 'C#'),
	(2, 'SQL'),
	(3, 'JS')

CREATE TABLE ProductCategories (
	ProductId INT FOREIGN KEY REFERENCES Products(Id),
	CategoryId INT FOREIGN KEY REFERENCES Categories(Id),
	PRIMARY KEY (ProductId, CategoryId)
);

INSERT INTO ProductCategories
VALUES
	(1, 1),
	(1, 2),
	(2, 3);

SELECT P.NAME as Products, C.NAME as Categories FROM Products P
LEFT JOIN ProductCategories PC
	ON P.Id = PC.ProductId
LEFT JOIN Categories C
	ON PC.CategoryId = C.Id;