#ifndef PENCILERROR_H
#define PENCILERROR_H

#include <QCoreApplication>
#include <QStringList>

class DebugDetails
{
public:
    DebugDetails();

    void collect(const DebugDetails &d);
    QString str();
    QString html();

    DebugDetails &operator<<(const QString &s);

private:
    void appendSystemInfo();
    QStringList mDatails;
};


class Status
{
    Q_DECLARE_TR_FUNCTIONS(Status)

public:
    enum ErrorCode
    {
        OK = 0,
        SAFE,
        FAIL,
        CANCELED,
        FILE_NOT_FOUND,
        NOT_SUPPORTED,
        INVALID_ARGUMENT,
        NOT_IMPLEMENTED_YET,
        ERROR_FILE_CANNOT_OPEN,
        ERROR_INVALID_XML_FILE,
        ERROR_INVALID_PENCIL_FILE,
        ERROR_MINIZ_FAIL,
        ERROR_INVALID_LAYER_TYPE,
        ERROR_INVALID_FRAME_NUMBER,
        ERROR_LOAD_IMAGE_FAIL,
        ERROR_LOAD_SOUND_FILE,
        ERROR_FFMPEG_NOT_FOUND,
        ERROR_NEED_AT_LEAST_ONE_CAMERA_LAYER
    };

    Status(const ErrorCode &code);
    Status(const ErrorCode &code, const QString &description);
    Status(const ErrorCode &code, const DebugDetails &details);
    Status(const ErrorCode &code, const DebugDetails &details, const QString &title,
           const QString &description);

    ErrorCode code() const;
    bool ok() const;
    QString message() const;
    QString title() const;
    DebugDetails details() const;

    void setTitle(const QString &title);
    void setDescription(const QString &desc);
    void setDetails(const DebugDetails &details);

    bool operator==(const ErrorCode &code) const;
    bool operator!=(const ErrorCode &code) const;
};


// clang-format off

#ifndef STATUS_CHECK
#define STATUS_CHECK( x )\
	{ Status st = (x); if (!st.ok()) { return st; } }
#endif

#ifndef STATUS_FAILED
#define STATUS_FAILED(stcode) ((int)stcode >= (int)Status::FAIL)
#endif

// clang-format on

#endif//PENCILERROR_H