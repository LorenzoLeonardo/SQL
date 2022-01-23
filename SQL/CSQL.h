#pragma once

class CSQL
{
protected:
	int m_nRow;
	int m_nCol;
public:
	CSQL();
	~CSQL();

	int	 GetRows()
	{
		return m_nRow;
	}
	int	GetColumns()
	{
		return m_nCol;
	}
	bool ConnectDatabase();
	void DisconnectDatabase();
	
};

