USE [Projet_POO]
GO
/****** Object:  StoredProcedure [dbo].[Modifier_Article]    Script Date: 11/12/2023 20:16:02 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO


CREATE PROC Modifier_Article
@Id_Art int,
@Prix_Art float,
@Nom_Art char(40),
@Couleur_Art char(40),
@Stock_Art int,
@Taux_TVA_Art float

AS
	UPDATE Article
	SET Prix_Art = @Prix_Art,
	Nom_Art = @Nom_Art,
	Couleur_Art = @Couleur_Art,
	Stock_Art = @Stock_Art,
	Taux_TVA_Art = @Taux_TVA_Art
	WHERE Id_Art = @Id_Art