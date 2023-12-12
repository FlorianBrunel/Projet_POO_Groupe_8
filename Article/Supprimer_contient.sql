USE [Projet_POO]
GO
/****** Object:  StoredProcedure [dbo].[Supprimer_Contient]    Script Date: 11/12/2023 20:28:08 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROC Supprimer_Contient

@Id_Art int,
@Ref_Com varchar(50)

AS 
	DELETE FROM Contient WHERE Id_Art = @Id_Art AND Id_Com = (SELECT Id_Com FROM Commande WHERE Ref_Com = @Ref_Com)