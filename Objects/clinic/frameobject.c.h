/*[clinic input]
preserve
[clinic start generated code]*/

#if defined(Py_BUILD_CORE) && !defined(Py_BUILD_CORE_MODULE)
#  include "pycore_gc.h"          // PyGC_Head
#  include "pycore_runtime.h"     // _Py_ID()
#endif
#include "pycore_critical_section.h"// Py_BEGIN_CRITICAL_SECTION()
#include "pycore_modsupport.h"    // _PyArg_UnpackKeywords()

PyDoc_STRVAR(frame_new__doc__,
"frame(code, globals, locals, *, back=None, lasti=None)\n"
"--\n"
"\n"
"Create a frame object.\n"
"\n"
"  code\n"
"    a code object\n"
"  globals\n"
"    the globals dictionary\n"
"  locals\n"
"    the locals dictionary\n"
"  back\n"
"    the previous stack frame\n"
"  lasti\n"
"    current precise instruction\n"
"\n"
"The thread state is set to that of the calling frame.");

static PyObject *
frame_new_impl(PyTypeObject *type, PyCodeObject *code, PyObject *globals,
               PyObject *locals, PyObject *back, PyObject *lasti);

static PyObject *
frame_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
    PyObject *return_value = NULL;
    #if defined(Py_BUILD_CORE) && !defined(Py_BUILD_CORE_MODULE)

    #define NUM_KEYWORDS 5
    static struct {
        PyGC_Head _this_is_not_used;
        PyObject_VAR_HEAD
        Py_hash_t ob_hash;
        PyObject *ob_item[NUM_KEYWORDS];
    } _kwtuple = {
        .ob_base = PyVarObject_HEAD_INIT(&PyTuple_Type, NUM_KEYWORDS)
        .ob_hash = -1,
        .ob_item = { &_Py_ID(code), &_Py_ID(globals), &_Py_ID(locals), &_Py_ID(back), &_Py_ID(lasti), },
    };
    #undef NUM_KEYWORDS
    #define KWTUPLE (&_kwtuple.ob_base.ob_base)

    #else  // !Py_BUILD_CORE
    #  define KWTUPLE NULL
    #endif  // !Py_BUILD_CORE

    static const char * const _keywords[] = {"code", "globals", "locals", "back", "lasti", NULL};
    static _PyArg_Parser _parser = {
        .keywords = _keywords,
        .fname = "frame",
        .kwtuple = KWTUPLE,
    };
    #undef KWTUPLE
    PyObject *argsbuf[5];
    PyObject * const *fastargs;
    Py_ssize_t nargs = PyTuple_GET_SIZE(args);
    Py_ssize_t noptargs = nargs + (kwargs ? PyDict_GET_SIZE(kwargs) : 0) - 3;
    PyCodeObject *code;
    PyObject *globals;
    PyObject *locals;
    PyObject *back = Py_None;
    PyObject *lasti = Py_None;

    fastargs = _PyArg_UnpackKeywords(_PyTuple_CAST(args)->ob_item, nargs, kwargs, NULL, &_parser,
            /*minpos*/ 3, /*maxpos*/ 3, /*minkw*/ 0, /*varpos*/ 0, argsbuf);
    if (!fastargs) {
        goto exit;
    }
    if (!PyObject_TypeCheck(fastargs[0], &PyCode_Type)) {
        _PyArg_BadArgument("frame", "argument 'code'", (&PyCode_Type)->tp_name, fastargs[0]);
        goto exit;
    }
    code = (PyCodeObject *)fastargs[0];
    if (!PyDict_Check(fastargs[1])) {
        _PyArg_BadArgument("frame", "argument 'globals'", "dict", fastargs[1]);
        goto exit;
    }
    globals = fastargs[1];
    if (!PyDict_Check(fastargs[2])) {
        _PyArg_BadArgument("frame", "argument 'locals'", "dict", fastargs[2]);
        goto exit;
    }
    locals = fastargs[2];
    if (!noptargs) {
        goto skip_optional_kwonly;
    }
    if (fastargs[3]) {
        back = fastargs[3];
        if (!--noptargs) {
            goto skip_optional_kwonly;
        }
    }
    lasti = fastargs[4];
skip_optional_kwonly:
    return_value = frame_new_impl(type, code, globals, locals, back, lasti);

exit:
    return return_value;
}

PyDoc_STRVAR(frame_locals__doc__,
"Return the mapping used by the frame to look up local variables.");
#if defined(frame_locals_DOCSTR)
#   undef frame_locals_DOCSTR
#endif
#define frame_locals_DOCSTR frame_locals__doc__

#if !defined(frame_locals_DOCSTR)
#  define frame_locals_DOCSTR NULL
#endif
#if defined(FRAME_LOCALS_GETSETDEF)
#  undef FRAME_LOCALS_GETSETDEF
#  define FRAME_LOCALS_GETSETDEF {"f_locals", (getter)frame_locals_get, (setter)frame_locals_set, frame_locals_DOCSTR},
#else
#  define FRAME_LOCALS_GETSETDEF {"f_locals", (getter)frame_locals_get, NULL, frame_locals_DOCSTR},
#endif

static PyObject *
frame_locals_get_impl(PyFrameObject *self);

static PyObject *
frame_locals_get(PyObject *self, void *Py_UNUSED(context))
{
    PyObject *return_value = NULL;

    Py_BEGIN_CRITICAL_SECTION(self);
    return_value = frame_locals_get_impl((PyFrameObject *)self);
    Py_END_CRITICAL_SECTION();

    return return_value;
}

PyDoc_STRVAR(frame_lineno__doc__,
"Return the current line number in the frame.");
#if defined(frame_lineno_DOCSTR)
#   undef frame_lineno_DOCSTR
#endif
#define frame_lineno_DOCSTR frame_lineno__doc__

#if !defined(frame_lineno_DOCSTR)
#  define frame_lineno_DOCSTR NULL
#endif
#if defined(FRAME_LINENO_GETSETDEF)
#  undef FRAME_LINENO_GETSETDEF
#  define FRAME_LINENO_GETSETDEF {"f_lineno", (getter)frame_lineno_get, (setter)frame_lineno_set, frame_lineno_DOCSTR},
#else
#  define FRAME_LINENO_GETSETDEF {"f_lineno", (getter)frame_lineno_get, NULL, frame_lineno_DOCSTR},
#endif

static PyObject *
frame_lineno_get_impl(PyFrameObject *self);

static PyObject *
frame_lineno_get(PyObject *self, void *Py_UNUSED(context))
{
    PyObject *return_value = NULL;

    Py_BEGIN_CRITICAL_SECTION(self);
    return_value = frame_lineno_get_impl((PyFrameObject *)self);
    Py_END_CRITICAL_SECTION();

    return return_value;
}

PyDoc_STRVAR(frame_lasti__doc__,
"Return the index of the last attempted instruction in the frame.");
#if defined(frame_lasti_DOCSTR)
#   undef frame_lasti_DOCSTR
#endif
#define frame_lasti_DOCSTR frame_lasti__doc__

#if !defined(frame_lasti_DOCSTR)
#  define frame_lasti_DOCSTR NULL
#endif
#if defined(FRAME_LASTI_GETSETDEF)
#  undef FRAME_LASTI_GETSETDEF
#  define FRAME_LASTI_GETSETDEF {"f_lasti", (getter)frame_lasti_get, (setter)frame_lasti_set, frame_lasti_DOCSTR},
#else
#  define FRAME_LASTI_GETSETDEF {"f_lasti", (getter)frame_lasti_get, NULL, frame_lasti_DOCSTR},
#endif

static PyObject *
frame_lasti_get_impl(PyFrameObject *self);

static PyObject *
frame_lasti_get(PyObject *self, void *Py_UNUSED(context))
{
    PyObject *return_value = NULL;

    Py_BEGIN_CRITICAL_SECTION(self);
    return_value = frame_lasti_get_impl((PyFrameObject *)self);
    Py_END_CRITICAL_SECTION();

    return return_value;
}

PyDoc_STRVAR(frame_globals__doc__,
"Return the global variables in the frame.");
#if defined(frame_globals_DOCSTR)
#   undef frame_globals_DOCSTR
#endif
#define frame_globals_DOCSTR frame_globals__doc__

#if !defined(frame_globals_DOCSTR)
#  define frame_globals_DOCSTR NULL
#endif
#if defined(FRAME_GLOBALS_GETSETDEF)
#  undef FRAME_GLOBALS_GETSETDEF
#  define FRAME_GLOBALS_GETSETDEF {"f_globals", (getter)frame_globals_get, (setter)frame_globals_set, frame_globals_DOCSTR},
#else
#  define FRAME_GLOBALS_GETSETDEF {"f_globals", (getter)frame_globals_get, NULL, frame_globals_DOCSTR},
#endif

static PyObject *
frame_globals_get_impl(PyFrameObject *self);

static PyObject *
frame_globals_get(PyObject *self, void *Py_UNUSED(context))
{
    PyObject *return_value = NULL;

    Py_BEGIN_CRITICAL_SECTION(self);
    return_value = frame_globals_get_impl((PyFrameObject *)self);
    Py_END_CRITICAL_SECTION();

    return return_value;
}

PyDoc_STRVAR(frame_builtins__doc__,
"Return the built-in variables in the frame.");
#if defined(frame_builtins_DOCSTR)
#   undef frame_builtins_DOCSTR
#endif
#define frame_builtins_DOCSTR frame_builtins__doc__

#if !defined(frame_builtins_DOCSTR)
#  define frame_builtins_DOCSTR NULL
#endif
#if defined(FRAME_BUILTINS_GETSETDEF)
#  undef FRAME_BUILTINS_GETSETDEF
#  define FRAME_BUILTINS_GETSETDEF {"f_builtins", (getter)frame_builtins_get, (setter)frame_builtins_set, frame_builtins_DOCSTR},
#else
#  define FRAME_BUILTINS_GETSETDEF {"f_builtins", (getter)frame_builtins_get, NULL, frame_builtins_DOCSTR},
#endif

static PyObject *
frame_builtins_get_impl(PyFrameObject *self);

static PyObject *
frame_builtins_get(PyObject *self, void *Py_UNUSED(context))
{
    PyObject *return_value = NULL;

    Py_BEGIN_CRITICAL_SECTION(self);
    return_value = frame_builtins_get_impl((PyFrameObject *)self);
    Py_END_CRITICAL_SECTION();

    return return_value;
}

PyDoc_STRVAR(frame_code__doc__,
"Return the code object being executed in this frame.");
#if defined(frame_code_DOCSTR)
#   undef frame_code_DOCSTR
#endif
#define frame_code_DOCSTR frame_code__doc__

#if !defined(frame_code_DOCSTR)
#  define frame_code_DOCSTR NULL
#endif
#if defined(FRAME_CODE_GETSETDEF)
#  undef FRAME_CODE_GETSETDEF
#  define FRAME_CODE_GETSETDEF {"f_code", (getter)frame_code_get, (setter)frame_code_set, frame_code_DOCSTR},
#else
#  define FRAME_CODE_GETSETDEF {"f_code", (getter)frame_code_get, NULL, frame_code_DOCSTR},
#endif

static PyObject *
frame_code_get_impl(PyFrameObject *self);

static PyObject *
frame_code_get(PyObject *self, void *Py_UNUSED(context))
{
    return frame_code_get_impl((PyFrameObject *)self);
}

#if !defined(frame_back_DOCSTR)
#  define frame_back_DOCSTR NULL
#endif
#if defined(FRAME_BACK_GETSETDEF)
#  undef FRAME_BACK_GETSETDEF
#  define FRAME_BACK_GETSETDEF {"f_back", (getter)frame_back_get, (setter)frame_back_set, frame_back_DOCSTR},
#else
#  define FRAME_BACK_GETSETDEF {"f_back", (getter)frame_back_get, NULL, frame_back_DOCSTR},
#endif

static PyObject *
frame_back_get_impl(PyFrameObject *self);

static PyObject *
frame_back_get(PyObject *self, void *Py_UNUSED(context))
{
    PyObject *return_value = NULL;

    Py_BEGIN_CRITICAL_SECTION(self);
    return_value = frame_back_get_impl((PyFrameObject *)self);
    Py_END_CRITICAL_SECTION();

    return return_value;
}

PyDoc_STRVAR(frame_trace_opcodes__doc__,
"Return True if opcode tracing is enabled, False otherwise.");
#if defined(frame_trace_opcodes_DOCSTR)
#   undef frame_trace_opcodes_DOCSTR
#endif
#define frame_trace_opcodes_DOCSTR frame_trace_opcodes__doc__

#if !defined(frame_trace_opcodes_DOCSTR)
#  define frame_trace_opcodes_DOCSTR NULL
#endif
#if defined(FRAME_TRACE_OPCODES_GETSETDEF)
#  undef FRAME_TRACE_OPCODES_GETSETDEF
#  define FRAME_TRACE_OPCODES_GETSETDEF {"f_trace_opcodes", (getter)frame_trace_opcodes_get, (setter)frame_trace_opcodes_set, frame_trace_opcodes_DOCSTR},
#else
#  define FRAME_TRACE_OPCODES_GETSETDEF {"f_trace_opcodes", (getter)frame_trace_opcodes_get, NULL, frame_trace_opcodes_DOCSTR},
#endif

static PyObject *
frame_trace_opcodes_get_impl(PyFrameObject *self);

static PyObject *
frame_trace_opcodes_get(PyObject *self, void *Py_UNUSED(context))
{
    PyObject *return_value = NULL;

    Py_BEGIN_CRITICAL_SECTION(self);
    return_value = frame_trace_opcodes_get_impl((PyFrameObject *)self);
    Py_END_CRITICAL_SECTION();

    return return_value;
}

#if !defined(frame_trace_opcodes_DOCSTR)
#  define frame_trace_opcodes_DOCSTR NULL
#endif
#if defined(FRAME_TRACE_OPCODES_GETSETDEF)
#  undef FRAME_TRACE_OPCODES_GETSETDEF
#  define FRAME_TRACE_OPCODES_GETSETDEF {"f_trace_opcodes", (getter)frame_trace_opcodes_get, (setter)frame_trace_opcodes_set, frame_trace_opcodes_DOCSTR},
#else
#  define FRAME_TRACE_OPCODES_GETSETDEF {"f_trace_opcodes", NULL, (setter)frame_trace_opcodes_set, NULL},
#endif

static int
frame_trace_opcodes_set_impl(PyFrameObject *self, PyObject *value);

static int
frame_trace_opcodes_set(PyObject *self, PyObject *value, void *Py_UNUSED(context))
{
    int return_value;

    Py_BEGIN_CRITICAL_SECTION(self);
    return_value = frame_trace_opcodes_set_impl((PyFrameObject *)self, value);
    Py_END_CRITICAL_SECTION();

    return return_value;
}

#if !defined(frame_lineno_DOCSTR)
#  define frame_lineno_DOCSTR NULL
#endif
#if defined(FRAME_LINENO_GETSETDEF)
#  undef FRAME_LINENO_GETSETDEF
#  define FRAME_LINENO_GETSETDEF {"f_lineno", (getter)frame_lineno_get, (setter)frame_lineno_set, frame_lineno_DOCSTR},
#else
#  define FRAME_LINENO_GETSETDEF {"f_lineno", NULL, (setter)frame_lineno_set, NULL},
#endif

static int
frame_lineno_set_impl(PyFrameObject *self, PyObject *value);

static int
frame_lineno_set(PyObject *self, PyObject *value, void *Py_UNUSED(context))
{
    int return_value;

    Py_BEGIN_CRITICAL_SECTION(self);
    return_value = frame_lineno_set_impl((PyFrameObject *)self, value);
    Py_END_CRITICAL_SECTION();

    return return_value;
}

PyDoc_STRVAR(frame_trace__doc__,
"Return the trace function for this frame, or None if no trace function is set.");
#if defined(frame_trace_DOCSTR)
#   undef frame_trace_DOCSTR
#endif
#define frame_trace_DOCSTR frame_trace__doc__

#if !defined(frame_trace_DOCSTR)
#  define frame_trace_DOCSTR NULL
#endif
#if defined(FRAME_TRACE_GETSETDEF)
#  undef FRAME_TRACE_GETSETDEF
#  define FRAME_TRACE_GETSETDEF {"f_trace", (getter)frame_trace_get, (setter)frame_trace_set, frame_trace_DOCSTR},
#else
#  define FRAME_TRACE_GETSETDEF {"f_trace", (getter)frame_trace_get, NULL, frame_trace_DOCSTR},
#endif

static PyObject *
frame_trace_get_impl(PyFrameObject *self);

static PyObject *
frame_trace_get(PyObject *self, void *Py_UNUSED(context))
{
    PyObject *return_value = NULL;

    Py_BEGIN_CRITICAL_SECTION(self);
    return_value = frame_trace_get_impl((PyFrameObject *)self);
    Py_END_CRITICAL_SECTION();

    return return_value;
}

#if !defined(frame_trace_DOCSTR)
#  define frame_trace_DOCSTR NULL
#endif
#if defined(FRAME_TRACE_GETSETDEF)
#  undef FRAME_TRACE_GETSETDEF
#  define FRAME_TRACE_GETSETDEF {"f_trace", (getter)frame_trace_get, (setter)frame_trace_set, frame_trace_DOCSTR},
#else
#  define FRAME_TRACE_GETSETDEF {"f_trace", NULL, (setter)frame_trace_set, NULL},
#endif

static int
frame_trace_set_impl(PyFrameObject *self, PyObject *value);

static int
frame_trace_set(PyObject *self, PyObject *value, void *Py_UNUSED(context))
{
    int return_value;

    Py_BEGIN_CRITICAL_SECTION(self);
    return_value = frame_trace_set_impl((PyFrameObject *)self, value);
    Py_END_CRITICAL_SECTION();

    return return_value;
}

PyDoc_STRVAR(frame_generator__doc__,
"Return the generator or coroutine associated with this frame, or None.");
#if defined(frame_generator_DOCSTR)
#   undef frame_generator_DOCSTR
#endif
#define frame_generator_DOCSTR frame_generator__doc__

#if !defined(frame_generator_DOCSTR)
#  define frame_generator_DOCSTR NULL
#endif
#if defined(FRAME_GENERATOR_GETSETDEF)
#  undef FRAME_GENERATOR_GETSETDEF
#  define FRAME_GENERATOR_GETSETDEF {"f_generator", (getter)frame_generator_get, (setter)frame_generator_set, frame_generator_DOCSTR},
#else
#  define FRAME_GENERATOR_GETSETDEF {"f_generator", (getter)frame_generator_get, NULL, frame_generator_DOCSTR},
#endif

static PyObject *
frame_generator_get_impl(PyFrameObject *self);

static PyObject *
frame_generator_get(PyObject *self, void *Py_UNUSED(context))
{
    PyObject *return_value = NULL;

    Py_BEGIN_CRITICAL_SECTION(self);
    return_value = frame_generator_get_impl((PyFrameObject *)self);
    Py_END_CRITICAL_SECTION();

    return return_value;
}

PyDoc_STRVAR(frame_clear__doc__,
"clear($self, /)\n"
"--\n"
"\n"
"Clear all references held by the frame.");

#define FRAME_CLEAR_METHODDEF    \
    {"clear", (PyCFunction)frame_clear, METH_NOARGS, frame_clear__doc__},

static PyObject *
frame_clear_impl(PyFrameObject *self);

static PyObject *
frame_clear(PyObject *self, PyObject *Py_UNUSED(ignored))
{
    PyObject *return_value = NULL;

    Py_BEGIN_CRITICAL_SECTION(self);
    return_value = frame_clear_impl((PyFrameObject *)self);
    Py_END_CRITICAL_SECTION();

    return return_value;
}

PyDoc_STRVAR(frame___sizeof____doc__,
"__sizeof__($self, /)\n"
"--\n"
"\n"
"Return the size of the frame in memory, in bytes.");

#define FRAME___SIZEOF___METHODDEF    \
    {"__sizeof__", (PyCFunction)frame___sizeof__, METH_NOARGS, frame___sizeof____doc__},

static PyObject *
frame___sizeof___impl(PyFrameObject *self);

static PyObject *
frame___sizeof__(PyObject *self, PyObject *Py_UNUSED(ignored))
{
    PyObject *return_value = NULL;

    Py_BEGIN_CRITICAL_SECTION(self);
    return_value = frame___sizeof___impl((PyFrameObject *)self);
    Py_END_CRITICAL_SECTION();

    return return_value;
}
/*[clinic end generated code: output=f71bce041512872f input=a9049054013a1b77]*/
