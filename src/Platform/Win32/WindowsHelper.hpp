#ifndef WINDOWS_HELPER_HPP
#define WINDOWS_HELPER_HPP

// TODO: WM_DISPLAYCHANGE event handling (multi-monitor support)

struct WindowsHelper
{
	WindowsHelper();
	~WindowsHelper();

	void setIcon(HWND inHandle);
	void toggleFullscreen(HWND inHandle, const sf::Uint32 inStyle, const bool inWindowed, const sf::Vector2u& inResolution);
	float getScreenScalingFactor();
	int getRefreshRate();

private:
	PBYTE getIconDirectory(const int inResourceId);
	HICON getIconFromIconDirectory(PBYTE inIconDirectory, const uint inSize);
	DWORD sfmlWindowStyleToWin32WindowStyle(const sf::Uint32 inStyle);

	std::vector<HICON> m_hIcons;

	float m_screenScalingFactor = 0.0f;
	int m_refreshRate = 0;
};

#endif // WINDOWS_HELPER_HPP
