//
//  Singleton.h
//  Singleton
//
//  Created by david on 15/7/21.
//
//  instance for MRC and ARC



//.h 实现
#define SingletonH(methodName) + (instancetype)share##methodName;

#if __has_feature(objc_arc)
//.m文件实现
#define SingletonM(classNmae,methodName ) \
static classNmae *_Tool = nil;\
+ (id)allocWithZone:(struct _NSZone*)zone\
{\
    if(Tool == nil){\
        static dispatch_once_t onceToken;\
        dispatch_once(&onceToken, ^{\
            _Tool = [super allocWithZone:zone];\
        });\
    }\
    return _Tool;\
}\
\
- (id)init\
{\
    static dispatch_once_t onceToken;\
    dispatch_once(&onceToken, ^{\
        _Tool = [super init];\
    });\
    return _Tool;\
}\
\
+ (instancetype)share##methodName\
{\
    return [[self alloc] init];\
}

#else

#define SingletonM(classNmae,methodName ) \
static classNmae *_Tool = nil;\
+ (id)allocWithZone:(struct _NSZone*)zone\
{\
if(Tool == nil){\
static dispatch_once_t onceToken;\
dispatch_once(&onceToken, ^{\
_Tool = [super allocWithZone:zone];\
});\
}\
return _Tool;\
}\
\
- (id)init\
{\
static dispatch_once_t onceToken;\
dispatch_once(&onceToken, ^{\
_Tool = [super init];\
});\
return _Tool;\
}\
\
+ (instancetype)share##methodName\
{\
return [[self alloc] init];\
}\
\
- (oneway void)release\
{\
\
}\
\
- (id)retain\
{\
return self;\
}\
\
- (NSUInteger)retainCount\
{\
return 1;\
}

#endif