' save sheet as charset csv.
Sub saveCharsetCSV(sheet,filePath,charset)
	Set stream = CreateObject("ADODB.Stream")
	stream.Charset = charset
	stream.Mode = 3
	stream.Type = 2
	stream.Open
	Dim i, j
    i = 1
    j = 1
	For i = 1 to sheet.UsedRange.Rows.Count
		For j = 1 to sheet.UsedRange.Columns.Count
			if vbString = VarType(sheet.Cells(i, j)) then
				stream.WriteText """" & (sheet.Cells(i, j).Value & """,")
			else
				stream.WriteText (sheet.Cells(i, j).Value & ",")
			end if
		Next
		stream.WriteText (vbCrLf)
	Next		

	stream.SaveToFile filePath, 2
	stream.Close
	Set stream = Nothing
End Sub

' export csv.
Sub xlsxExportCsc(excelPath,ouputPath,worksheetCount,charset)
	' the Excel Application
	Dim objExcel
	' counter sheet.
	Dim counter
	' the worksheet we are currently getting data from
	Dim currentWorkSheet
	' the value of the current row and column of the current worksheet we are reading
	' Dim word
	Wscript.Echo "Reading Data from " & excelPath

	' Create an invisible version of Excel
	Set objExcel = CreateObject("Excel.Application")
	 
	' don't display any messages about documents needing to be converted
	' from  old Excel file formats
	objExcel.DisplayAlerts = 0
	 
	' open the excel document as read-only
	' open (path, confirmconversions, readonly)
	objExcel.Workbooks.open excelPath, false, true	 
	 
	' How many worksheets are in this Excel documents

	if workSheetCount=0 then
		worksheetCount = objExcel.Worksheets.Count
	end if
	 
	Wscript.Echo "We have " & workSheetCount & " worksheets"
		
	' const xlCurrentPlatformText = 6
	 
	' Loop through each worksheet
	For counter = 1 to workSheetCount
		Wscript.Echo "-----------------------------------------------" 
		Set currentWorkSheet = objExcel.ActiveWorkbook.Worksheets(counter)
		Wscript.Echo "Reading data from worksheet " & currentWorkSheet.Name '& vbCRLF

		wscript.echo "Save As:" & ouputPath & currentWorkSheet.Name & ".csv" '& vbCRLF
		saveCharsetCSV currentWorkSheet,ouputPath & currentWorkSheet.Name & ".csv",charset
		' currentWorkSheet.saveas ouputPath & currentWorkSheet.Name & ".csv", xlCurrentPlatformText
	 
		' We are done with the current worksheet, release the memory
		Set currentWorkSheet = Nothing
	Next
	 
	objExcel.Workbooks(1).Close
	objExcel.Quit

	Set currentWorkSheet = Nothing
	' We are done with the Excel object, release it from memory
	Set objExcel = Nothing
End Sub

' entry main.
Sub main()
	' the path to the excel file
	Dim excelPath
	Dim ouputPath
	' how many worksheets are in the current excel file
	Dim worksheetCount

	If wscript.arguments.Count <2  Then
		wscript.echo "Not Enought Parameters"
		wscript.exit(1)
	Else
		excelPath = wscript.arguments(0)
		ouputPath = wscript.arguments(1)
		if wscript.arguments.count>2 then
			worksheetCount = wscript.arguments(2)
		else
			worksheetCount = 0
		end if

	End If

	xlsxExportCsc excelPath,ouputPath,worksheetCount,"UTF-8"
End Sub

' exec main.
main