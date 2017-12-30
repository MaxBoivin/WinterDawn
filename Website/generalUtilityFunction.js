function toggleSection(sectionToToggle, buttID)
{	
	if (document.getElementById(sectionToToggle).style.display === 'none')
	{
		document.getElementById(sectionToToggle).style.display = 'block';
		if (buttID != undefined)
		{
			buttID.innerHTML = "-";
		}
	}
	else
	{
		document.getElementById(sectionToToggle).style.display = 'none';
		if (buttID != undefined)
		{
			buttID.innerHTML = "+";
		}
	}
}

function toggleSectionList(listID)
{	
	for (i = 1; i < listID.options.length; i++)
	{
		if (document.getElementById(listID.options[i].value) != null)
		{
			if (listID.options[i].selected === true)
			{	
				document.getElementById(listID.options[i].value).style.display = 'block';
			}
			else 
			{
				document.getElementById(listID.options[i].value).style.display = 'none';
			}
		}
	}
}

function isNumber(n) { return /^-?[\d.]+(?:e-?\d+)?$/.test(n); } 

function compareArray(array1, array2)
{
	var sameArray = true;
	if (array1.constructor === Array && array2.constructor === Array)
	{
		if (array1.length == array2.length)
		{
			for (i = 1; i < array1.length; i++)
			{
				if (array1[i] != array2[i])
				{
					sameArray = false;
				}
			}		
		}
		else
		{
			sameArray = false;
		}
	}
	else
	{
		sameArray = false;
	}
	return sameArray;
}

function getFormValue (formName)
{
	var formElements = document.getElementsByName(formName);
	var formValueSelected = []
	for (i = 0; i < formElements.length; i++)
	{
		if (formElements[i].checked)
		{
			formValueSelected.push(formElements[i].value);
		}
	}
	/*if (formValueSelected.length === 1)
	{
		return formValueSelected[0];
	}
	else 
	{
		if (formValueSelected.length > 1)
		{
			return formValueSelected;
		}
		else 
		{
			return undefined;
		}
	}*/
	if (formValueSelected.length > 0)
	{
		return formValueSelected;
	}
	else 
	{
		return undefined;
	}
}

function getFormIndex (formName)
{
	var formElements = document.getElementsByName(formName);
	var formIndexesSelected = []
	for (i = 0; i < formElements.length; i++)
	{
		if (formElements[i].checked)
		{
			formIndexesSelected.push(i);
		}
	}
	/*if (formIndexesSelected.length === 1)
	{
		return formIndexesSelected[0];
	}
	else 
	{
		if (formIndexesSelected.length > 1)
		{
			return formIndexesSelected;
		}
		else 
		{
			return undefined;
		}
	}*/
	if (formIndexesSelected.length > 0)
	{
		return formIndexeseSelected;
	}
	else 
	{
		return undefined;
	}
}

function getMultipleSelectIndex (multipleId)
{
	var multipleIndex = [];
	var multipleSelect = document.getElementById(multipleId);
	
	for (var i = 0; i < multipleSelect.options.length; i++)
	{
		if (multipleSelect.options[i].selected)
		{
			multipleIndex.push(i);
		}
	}
	if (multipleIndex.length > 0)
	{
		return multipleIndex;
	}
	else 
	{
		return undefined;
	}
}

function moveArrayElements (targetArray, arrayIndexes, moveDirection)
{
	arrayIndexes.sort();
	if (moveDirection > 0)
	{
		for (var i = arrayIndexes.length - 1; i >= 0; i--)
		{
			if (arrayIndexes[i] < targetArray.length - 1)
			{
				var tempValue = targetArray[arrayIndexes[i]+1];
				targetArray[arrayIndexes[i]+1] = targetArray[arrayIndexes[i]];
				targetArray[arrayIndexes[i]] = tempValue;
			}
		}
	}
	if (moveDirection < 0)
	{
		for (var i = 0; i < arrayIndexes.length; i++)
		{
			if (arrayIndexes[i] > 0)
			{
				var tempValue = targetArray[arrayIndexes[i]-1];
				targetArray[arrayIndexes[i]-1] = targetArray[arrayIndexes[i]];
				targetArray[arrayIndexes[i]] = tempValue;
			}
		}
	}
}

function findInArray (valueToFind, arrayToSearch)
{
	for (var i = 0; i < arrayToSearch.length; i++)
	{
		if (arrayToSearch[i] === valueToFind)
		{
			return i;
		}
	}
	return undefined;
}