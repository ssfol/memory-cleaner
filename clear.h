#pragma once

#ifdef DISKCLEANER_EXPORTS
#define DC_API __declspec(dllexport)
#else
#define DC_API __declspec(dllimport)
#endif

extern "C" {

    // Сколько логических дисков в системе
    DC_API int GetDiskCount();

    // Заполняет буфер буквами дисков ("C:\", "D:\"...). Возвращает число дисков.
    DC_API int GetDiskLetters(char* buffer, int bufferSize);

    // Очищает конкретный диск. Возвращает освобождённые байты или -1 при ошибке.
    DC_API long long CleanDisk(const char* driveLetter);

    // Очищает C и D. Возвращает суммарно освобождённые байты.
    DC_API long long CleanCAndD();

    // Очищает все найденные диски. Возвращает суммарно освобождённые байты.
    DC_API long long CleanAllDisks();

    // Текст последней ошибки
    DC_API const char* GetLastErrorMsg();
}
