const gulp = require("gulp");
const less = require("gulp-less");
const concat = require('gulp-concat');
const babel = require('gulp-babel');
const pug = require('gulp-pug');
var minifyCSS  = require('gulp-clean-css');

gulp.task('html', function(){
    return gulp.src('views/*.pug')
        .pipe(pug())
        .pipe(gulp.dest('build/html'))
});

gulp.task('css', function(){
    return gulp.src('public/less/*.less')
        .pipe(less())
        .pipe(concat('css.min.css'))
        .pipe(minifyCSS())
        .pipe(gulp.dest('build/css'))
});

gulp.task('js', function(){
    return gulp.src('public/src/jqr.js')
        .pipe(babel({
            presets: ['@babel/preset-env']
        }))
        .pipe(concat('app.min.js'))
        .pipe(gulp.dest('build/js'))
});

gulp.task('build', gulp.parallel('js', 'css', 'html'));