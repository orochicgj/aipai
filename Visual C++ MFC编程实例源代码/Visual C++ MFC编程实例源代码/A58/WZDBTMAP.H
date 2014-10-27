#ifndef WZDBITMAP_H
#define WZDBITMAP_H

class CWzdBitmap : public CBitmap
{
public:
	DECLARE_DYNAMIC(CWzdBitmap)

// Constructors
	CWzdBitmap();

	void CreateBitmapEx(CSize size);

// Implementation
public:
	virtual ~CWzdBitmap();

// Attributes
	int	m_Width;
	int m_Height;
// Operations

};
#endif
